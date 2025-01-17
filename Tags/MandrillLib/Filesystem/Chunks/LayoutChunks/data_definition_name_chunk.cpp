#include "mandrilllib-private-pch.h"

c_data_definition_name_chunk::c_data_definition_name_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	offsets(),
	entry_count()
{


	
}

c_data_definition_name_chunk::~c_data_definition_name_chunk()
{
	delete[] offsets;
}

BCS_RESULT c_data_definition_name_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	read_entries();

	return rs;
}

void c_data_definition_name_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);

	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_string_character_index string_character_index = offsets[index];
		if (string_debugger)
		{
			const char* string = string_debugger->get_string_by_string_character_index(string_character_index);
			log_pad(); console_write_line_verbose("\t0x%08X\t0x%08X\t%s", index, string_character_index.offset, string);
		}
		else
		{
			log_pad(); console_write_line_verbose("\t0x%08X\t0x%08X", index, string_character_index.offset);
		}
	}
}

BCS_RESULT c_data_definition_name_chunk::set_data(const void* data, unsigned long data_size)
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = c_chunk::set_data(data, data_size)))
	{
		return rs;
	}

	is_big_endian = false;
	read_entries();

	return rs;
}

void c_data_definition_name_chunk::read_entries()
{
	if (offsets)
	{
		delete[] offsets;
	}

	entry_count = chunk_size / sizeof(*offsets);
	if (entry_count > 0)
	{
		const s_tag_persist_string_character_index* src_offsets = reinterpret_cast<const s_tag_persist_string_character_index*>(get_chunk_data_start());
		offsets = new() s_tag_persist_string_character_index[entry_count];
		for (unsigned long entry_index = 0; entry_index < entry_count; entry_index++)
		{
			s_tag_persist_string_character_index& offset = offsets[entry_index];
			offset = src_offsets[entry_index];
			chunk_byteswap_inplace(offset);
		}
	}
}

