#include "halo3tagfiletest-private-pch.h"

c_tag_block_chunk::c_tag_block_chunk(void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader) :
	c_typed_single_tag_file_reader_chunk(chunk_data, parent, reader),
	blockdata_pos(),
	metadata_pos(),
	block_entry(),
	structure_entry(),
	block_name(),
	struct_name(),
	tag_block_chunk_header(),
	block_data_size(),
	struct_size()
{
	REFERENCE_ASSERT(reader);

	tag_block_chunk_header = *reinterpret_cast<s_tag_block_chunk_header*>(chunk_data_begin);
	chunk_data_begin += sizeof(s_tag_block_chunk_header);

	debug_point;

	unsigned long current_block_index = reader.metadata_stack.top();
	reader.metadata_stack.pop();

	block_entry = &reader.layout_reader.block_definitions_chunk->entries[current_block_index];
	block_name = reader.layout_reader.string_data_chunk->chunk_data_begin + block_entry->name_string_offset;
	structure_entry = &reader.layout_reader.structure_definitions_chunk->entries[block_entry->structure_entry_index];
	struct_name = reader.layout_reader.string_data_chunk->chunk_data_begin + structure_entry->name_string_offset;
	struct_size = reader.layout_reader.calculate_structure_size_by_index(block_entry->structure_entry_index);
	block_data_size = struct_size * tag_block_chunk_header.count;

	char* const block_data = chunk_data_begin;
	char* const metadata_data = block_data + block_data_size;
	chunk_data_begin = metadata_data;

	blockdata_pos = block_data;
	metadata_pos = metadata_data;

	log_pad(); log_signature(); console_write_line("count:0x%08X\tstruct_index:0x%08X\t%s", tag_block_chunk_header.count, tag_block_chunk_header.struct_index, block_name);
	log_pad(); console_write_line("calculated structure size for %s", struct_name);
	log_pad(); console_write_line("> 0x%08lX", struct_size);

	auto stack_start_size = reader.metadata_stack.size();


	for (unsigned long block_index = 0; block_index < tag_block_chunk_header.count; block_index++)
	{
		read_structure_metadata(*structure_entry);
	}

	bool has_children = metadata_pos < chunk_data_end;
	if (has_children)
	{
		parse_children(&reader);
		ASSERT(children != nullptr);
		unsigned long child_count = 0;
		for (c_chunk** child_iter = children; children && *child_iter; child_iter++)
		{
			c_tag_struct_chunk* tag_struct_chunk = dynamic_cast<c_tag_struct_chunk*>(*child_iter);
			ASSERT(tag_struct_chunk != nullptr);
			child_count++;
		}
		ASSERT(child_count == tag_block_chunk_header.count);
	}

	auto stack_end_size = reader.metadata_stack.size();
	ASSERT(stack_start_size == stack_end_size);

	for (unsigned long block_index = 0; block_index < tag_block_chunk_header.count; block_index++)
	{
		c_tag_struct_chunk* tag_struct_chunk = nullptr;
		if (has_children)
		{
			tag_struct_chunk = dynamic_cast<c_tag_struct_chunk*>(children[block_index]);
			ASSERT(tag_struct_chunk != nullptr);
		}
		read_structure_data(*structure_entry, blockdata_pos, tag_struct_chunk);
		blockdata_pos += struct_size;
	}
}

c_tag_block_chunk::~c_tag_block_chunk()
{

}

void c_tag_block_chunk::log_impl(c_string_data_chunk* string_data_chunk) const
{
	console_write_line("count:0x%08X\tstruct_index:0x%08X\t%s\n", tag_block_chunk_header.count, tag_block_chunk_header.struct_index, block_name);

	debug_point;
}

void c_tag_block_chunk::read_structure_metadata(s_struct_definition_entry& structure_entry)
{
	std::stack<unsigned long> metadata_stack;
	read_structure_metadata_impl(structure_entry, metadata_stack);

	/*if (verbose)*/ { log_pad(); console_write("> read_structure_metadata %u", static_cast<unsigned long>(metadata_stack.size())); }
	while (metadata_stack.size() > 0)
	{
		unsigned long metadata = metadata_stack.top();
		metadata_stack.pop();
		reader.metadata_stack.push(metadata);
	}
	/*if (verbose)*/ { console_write_line(" %u", static_cast<unsigned long>(reader.metadata_stack.size())); }
}

void c_tag_block_chunk::read_structure_metadata_impl(s_struct_definition_entry& structure_entry, std::stack<unsigned long>& metadata_stack) const
{
	for (unsigned long field_index = structure_entry.fields_start_index;; field_index++)
	{
		s_field_entry& field_entry = reader.layout_reader.fields_chunk->entries[field_index];
		s_tag_field_type_entry& tag_field_type = reader.layout_reader.tag_field_types_chunk->entries[field_entry.tag_field_type_index];

		const char* type_string = reader.layout_reader.string_data_chunk->chunk_data_begin + tag_field_type.name_string_offset;
		const char* name_string = reader.layout_reader.string_data_chunk->chunk_data_begin + field_entry.name_string_offset;

		blofeld::e_field field_type;
		BCS_RESULT rs = blofeld::tag_field_type_to_field(type_string, field_type);
		ASSERT(BCS_SUCCEEDED(rs));

		if (tag_field_type.metadata)
		{
			switch (field_type)
			{
			case blofeld::_field_block:
			{
				debug_point;
				s_block_definition_entry& block_entry = reader.layout_reader.block_definitions_chunk->entries[field_entry.metadata];
				const char* block_name = reader.layout_reader.string_data_chunk->chunk_data_begin + block_entry.name_string_offset;
				/*if (verbose)*/ { log_pad(); console_write_line("\tpushing block %s", block_name); }
				metadata_stack.push(field_entry.metadata);
				debug_point;
			}
			break;
			case blofeld::_field_tag_reference:
			case blofeld::_field_string_id:
			case blofeld::_field_old_string_id:
			case blofeld::_field_data:
				break;
			case blofeld::_field_struct:
			{
				unsigned long structure_entry_index = field_entry.metadata;
				auto& structure_entry = reader.layout_reader.structure_definitions_chunk->entries[structure_entry_index];
				read_structure_metadata_impl(structure_entry, metadata_stack);
			}
			break;
			default:
				throw;
			}
		}

		if (field_type == blofeld::_field_terminator)
		{
			break;
		}
	}
}

#define write_pad()
#define verbose true
void c_tag_block_chunk::read_structure_data(s_struct_definition_entry& structure_entry, const char* structure_data_pos, c_tag_struct_chunk* tag_struct_chunk)
{
	char* struct_name = reader.layout_reader.string_data_chunk->chunk_data_begin + structure_entry.name_string_offset;
	if (verbose) { write_pad(); console_write_line("STRUCT> %s", struct_name); }

	unsigned long metadata_child_index = 0;
	for (unsigned long field_index = structure_entry.fields_start_index;; field_index++)
	{
		s_field_entry& field_entry = reader.layout_reader.fields_chunk->entries[field_index];
		s_tag_field_type_entry& tag_field_type = reader.layout_reader.tag_field_types_chunk->entries[field_entry.tag_field_type_index];

		const char* type_string = reader.layout_reader.string_data_chunk->chunk_data_begin + tag_field_type.name_string_offset;
		const char* name_string = reader.layout_reader.string_data_chunk->chunk_data_begin + field_entry.name_string_offset;

		blofeld::e_field field_type;
		BCS_RESULT rs = blofeld::tag_field_type_to_field(type_string, field_type);
		ASSERT(BCS_SUCCEEDED(rs));


		unsigned long field_size = tag_field_type.size;

		if (tag_field_type.metadata)
		{
			ASSERT(tag_struct_chunk);
		}

		switch (field_type)
		{
		case blofeld::_field_struct:
		{
			unsigned long structure_size = reader.layout_reader.calculate_structure_size_by_index(field_entry.metadata);
			field_size = structure_size;
		}
		break;
		case blofeld::_field_array:
		{
			s_array_entry& array_entry = reader.layout_reader.array_definitions_chunk->entries[field_entry.metadata];
			unsigned long array_structure_size = reader.layout_reader.calculate_structure_size_by_index(array_entry.structure_index);
			unsigned long array_size = array_structure_size * array_entry.count;
			field_size = array_size;
		}
		break;
		case blofeld::_field_pad:
		{
			unsigned long pad_size = field_entry.metadata;
			field_size = pad_size;
		}
		break;
		}

		switch (field_type)
		{
		case blofeld::_field_struct:
		{
			ASSERT(tag_struct_chunk != nullptr);
			c_chunk* field_chunk = tag_struct_chunk->children[metadata_child_index++];
			c_tag_struct_chunk* tag_struct_chunk = dynamic_cast<c_tag_struct_chunk*>(field_chunk);
			ASSERT(tag_struct_chunk != nullptr);

			unsigned long structure_entry_index = field_entry.metadata;
			auto& structure_entry = reader.layout_reader.structure_definitions_chunk->entries[structure_entry_index];
			char* struct_name = reader.layout_reader.string_data_chunk->chunk_data_begin + structure_entry.name_string_offset;

			read_structure_data(structure_entry, structure_data_pos, tag_struct_chunk);
			debug_point;

		}
		break;
		case blofeld::_field_tag_reference:
		{
			ASSERT(tag_struct_chunk != nullptr);
			c_chunk* field_chunk = tag_struct_chunk->children[metadata_child_index++];
			c_tag_reference_chunk* tag_reference_chunk = dynamic_cast<c_tag_reference_chunk*>(field_chunk);
			ASSERT(tag_reference_chunk != nullptr);

		}
		break;
		case blofeld::_field_old_string_id:
		case blofeld::_field_string_id:
		{
			ASSERT(tag_struct_chunk != nullptr);
			c_chunk* field_chunk = tag_struct_chunk->children[metadata_child_index++];
			c_tag_string_id_chunk* tag_string_id_chunk = dynamic_cast<c_tag_string_id_chunk*>(field_chunk);
			ASSERT(tag_string_id_chunk != nullptr);

			const s_tag_data* data = reinterpret_cast<const s_tag_data*>(structure_data_pos);
			if (verbose) { write_pad(); console_write_line("%s %s '%s'", type_string, name_string, tag_string_id_chunk->string); }
			debug_point;
		}
		break;
		case blofeld::_field_data:
		{
			ASSERT(tag_struct_chunk != nullptr);
			c_chunk* field_chunk = tag_struct_chunk->children[metadata_child_index++];
			c_tag_data_chunk* tag_data_chunk = dynamic_cast<c_tag_data_chunk*>(field_chunk);
			ASSERT(tag_data_chunk != nullptr);

			const s_tag_data* data = reinterpret_cast<const s_tag_data*>(structure_data_pos);
			if (verbose) { write_pad(); console_write_line("%s %s size:%li", type_string, name_string, data->size); }
			debug_point;
		}
		break;
		case blofeld::_field_block:
		{
			ASSERT(tag_struct_chunk != nullptr);
			c_chunk* field_chunk = tag_struct_chunk->children[metadata_child_index++];
			c_tag_block_chunk* tag_block_chunk = dynamic_cast<c_tag_block_chunk*>(field_chunk);
			ASSERT(tag_block_chunk != nullptr);

			s_block_definition_entry& block_entry = reader.layout_reader.block_definitions_chunk->entries[field_entry.metadata];
			auto& structure_entry = reader.layout_reader.structure_definitions_chunk->entries[block_entry.structure_entry_index];
			char* block_name = reader.layout_reader.string_data_chunk->chunk_data_begin + block_entry.name_string_offset;
			char* struct_name = reader.layout_reader.string_data_chunk->chunk_data_begin + structure_entry.name_string_offset;

			const s_tag_block* block = reinterpret_cast<const s_tag_block*>(structure_data_pos);
			if (verbose) { write_pad(); console_write_line("%s %s count:%li", type_string, name_string, block->count); }

			debug_point;

			debug_point;

			break;
		}
		case blofeld::_field_char_integer:
		case blofeld::_field_char_enum:
		{
			const long _number = *reinterpret_cast<const char*>(structure_data_pos);
			if (verbose) { write_pad(); console_write_line("%s %s %li", type_string, name_string, _number); }
			debug_point;
			break;
		}
		case blofeld::_field_short_integer:
		case blofeld::_field_word_flags:
		case blofeld::_field_enum:
		{
			const long _number = *reinterpret_cast<const short*>(structure_data_pos);
			if (verbose) { write_pad(); console_write_line("%s %s %li", type_string, name_string, _number); }
			debug_point;
			break;
		}
		case blofeld::_field_long_integer:
		{
			const long _number = *reinterpret_cast<const long*>(structure_data_pos);
			if (verbose) { write_pad(); console_write_line("%s %s %li", type_string, name_string, _number); }
			debug_point;
			break;
		}
		case blofeld::_field_real:
		case blofeld::_field_real_fraction:
		{
			const real _real = *reinterpret_cast<const real*>(structure_data_pos);
			if (verbose) { write_pad(); console_write_line("%s %s %f", type_string, name_string, _real); }
			debug_point;
			break;
		}
		case blofeld::_field_real_point_3d:
		{
			const real_vector3d _real3 = *reinterpret_cast<const real_vector3d*>(structure_data_pos);
			if (verbose) { write_pad(); console_write_line("%s %s %f %f %f", type_string, name_string, _real3.i, _real3.j, _real3.k); }
			debug_point;
			break;
		}
		case blofeld::_field_real_plane_3d:
		{
			const real_vector4d _real4 = *reinterpret_cast<const real_vector4d*>(structure_data_pos);
			if (verbose) { write_pad(); console_write_line("%s %s %f %f %f %f", type_string, name_string, _real4.i, _real4.j, _real4.k, _real4.w); }
			debug_point;
			break;
		}
		case blofeld::_field_custom:
		case blofeld::_field_pad:
		case blofeld::_field_terminator:
			break;
		}

		structure_data_pos += field_size;

		if (field_type == blofeld::_field_terminator)
		{
			goto end;
		}
	}
end:;
}

/*

class c_tag_block_chunk : public c_typed_chunk<'tgbl'>
{
public:

	void write_pad()
	{
		log_pad();
		for (int i = 0; i < _depth; i++)
		{
			console_write("  ");
		}
	}

	void read_structure_metadata(s_struct_definition_entry& structure_entry)
	{
		std::stack<unsigned long> metadata_stack;
		read_structure_metadata_impl(structure_entry, metadata_stack);

		if (verbose) { log_pad(); console_write("> read_structure_metadata %u", static_cast<unsigned long>(metadata_stack.size())); }
		while (metadata_stack.size() > 0)
		{
			unsigned long metadata = metadata_stack.top();
			metadata_stack.pop();
			high_level_transplant.metadata_stack.push(metadata);
		}
		if (verbose) { console_write_line(" %u", static_cast<unsigned long>(high_level_transplant.metadata_stack.size())); }
	}

	void read_structure_metadata_impl(s_struct_definition_entry& structure_entry, std::stack<unsigned long>& metadata_stack)
	{
		for (unsigned long field_index = structure_entry.fields_start_index;; field_index++)
		{
			s_field_entry& field_entry = high_level_transplant.fields_chunk->entries[field_index];
			s_tag_field_type_entry& tag_field_type = high_level_transplant.tag_field_types_chunk->entries[field_entry.tag_field_type_index];

			const char* type_string = high_level_transplant.string_data_chunk->chunk_data_begin + tag_field_type.name_string_offset;
			const char* name_string = high_level_transplant.string_data_chunk->chunk_data_begin + field_entry.name_string_offset;

			blofeld::e_field field_type;
			BCS_RESULT rs = blofeld::tag_field_type_to_field(type_string, field_type);
			ASSERT(BCS_SUCCEEDED(rs));

			if (tag_field_type.metadata)
			{
				switch (field_type)
				{
				case blofeld::_field_block:
				{
					debug_point;
					s_block_definition_entry& block_entry = high_level_transplant.block_definitions_chunk->entries[field_entry.metadata];
					const char* block_name = high_level_transplant.string_data_chunk->chunk_data_begin + block_entry.name_string_offset;
					if (verbose) { log_pad(); console_write_line("\tpushing block %s", block_name); }
					metadata_stack.push(field_entry.metadata);
					debug_point;
				}
				break;
				case blofeld::_field_tag_reference:
				case blofeld::_field_string_id:
				case blofeld::_field_old_string_id:
				case blofeld::_field_data:
					break;
				case blofeld::_field_struct:
				{
					unsigned long structure_entry_index = field_entry.metadata;
					auto& structure_entry = high_level_transplant.structure_definitions_chunk->entries[structure_entry_index];
					read_structure_metadata_impl(structure_entry, metadata_stack);
				}
				break;
				default:
					throw;
				}
			}

			if (field_type == blofeld::_field_terminator)
			{
				break;
			}
		}
	}


	c_tag_block_chunk(void* chunk_data, c_chunk& parent) :
		c_typed_chunk(chunk_data, &parent)
	{
		tag_block_chunk_header = *reinterpret_cast<s_tag_block_chunk_header*>(chunk_data_start);
		chunk_data_start += sizeof(s_tag_block_chunk_header);

		debug_point;

		unsigned long current_block_index = high_level_transplant.metadata_stack.top();
		high_level_transplant.metadata_stack.pop();

		block_entry = &high_level_transplant.block_definitions_chunk->entries[current_block_index];
		block_name = high_level_transplant.string_data_chunk->chunk_data_begin + block_entry->name_string_offset;
		structure_entry = &high_level_transplant.structure_definitions_chunk->entries[block_entry->structure_entry_index];
		struct_name = high_level_transplant.string_data_chunk->chunk_data_begin + structure_entry->name_string_offset;
		struct_size = high_level_transplant.calculate_structure_size_by_index(block_entry->structure_entry_index);
		block_data_size = struct_size * tag_block_chunk_header.count;

		char* const block_data = chunk_data_start;
		char* const metadata_data = block_data + block_data_size;

		blockdata_pos = block_data;
		metadata_pos = metadata_data;

		if (verbose)
		{
			log_pad(); printf("%.4s\tcount:0x%08X\tstruct_index:0x%08X\t%s\n", short_name, tag_block_chunk_header.count, tag_block_chunk_header.struct_index, block_name);
			log_pad(); console_write_line("calculated structure size for %s", struct_name);
			log_pad(); console_write_line("> 0x%08lX", struct_size);
		}

		auto stack_start_size = high_level_transplant.metadata_stack.size();


		for (unsigned long block_index = 0; block_index < tag_block_chunk_header.count; block_index++)
		{
			read_structure_metadata(*structure_entry);
		}

		bool has_children = metadata_pos < chunk_data_end;
		if (has_children)
		{
			chunk_data_start = metadata_pos;
			parse_children();
			ASSERT(children.size() == tag_block_chunk_header.count);
		}

		auto stack_end_size = high_level_transplant.metadata_stack.size();
		ASSERT(stack_start_size == stack_end_size);


		for (unsigned long block_index = 0; block_index < tag_block_chunk_header.count; block_index++)
		{
			c_tag_struct_chunk* tag_struct_chunk = nullptr;
			if (has_children)
			{
				tag_struct_chunk = dynamic_cast<c_tag_struct_chunk*>(children[block_index]);
				ASSERT(tag_struct_chunk != nullptr);
			}
			read_structure_data(*structure_entry, blockdata_pos, tag_struct_chunk);
			blockdata_pos += struct_size;
		}
	}
	virtual void log_impl() override
	{
		printf("%.4s\tcount:0x%08X\tstruct_index:0x%08X\t%s\n", short_name, tag_block_chunk_header.count, tag_block_chunk_header.struct_index, block_name);

		debug_point;
	}
	virtual void parse_children() override
	{
		unsigned long structure_chunk_index = 0;
		for (char* data_position = metadata_pos; data_position < chunk_data_end;)
		{
			if (verbose) { log_pad(); console_write_line("> read_structure_chunk %u", structure_chunk_index); }

			unsigned long chunk_signature = *reinterpret_cast<unsigned long*>(data_position);
			ASSERT(chunk_signature == c_tag_struct_chunk::type);

			c_tag_struct_chunk* chunk = new c_tag_struct_chunk(high_level_transplant, data_position, this);

			data_position = chunk->chunk_data_end;
			children.push_back(chunk);

			structure_chunk_index++;
		}
		debug_point;
	}
};

*/