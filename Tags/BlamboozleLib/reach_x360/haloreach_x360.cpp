#include "blamboozlelib-private-pch.h"

ptr32 haloreach_dump_base_address;
ptr32 haloreach_tag_layout_table_address;
unsigned long haloreach_num_tag_layouts;

const char* reach_x360_va_to_pointer(const char* data, ptr32 address)
{
	if (address == 0) return nullptr;

	// #TODO: get this dynamically
	address = reach_x360_va_to_rva(address); // convert from va to rva

	return reach_x360_pa_to_pointer(data, address);
}

const char* reach_x360_pa_to_pointer(const char* data, ptr32 address)
{
	if (address == 0) return nullptr;

	const char* executable_image_data = nullptr;
	MINIDUMP_HEADER const& minidump_header = *reinterpret_cast<const MINIDUMP_HEADER*>(data);
	if (minidump_header.Signature == MINIDUMP_SIGNATURE)
	{
		static const MINIDUMP_DIRECTORY* minidump_directories = reinterpret_cast<const MINIDUMP_DIRECTORY*>(data + minidump_header.StreamDirectoryRva);

		static const MINIDUMP_DIRECTORY* minidump_memory64_list_directory = nullptr;
		if (minidump_memory64_list_directory == nullptr)
		{
			for (unsigned long minidump_stream_index = 0; minidump_stream_index < minidump_header.NumberOfStreams; minidump_stream_index++)
			{
				const MINIDUMP_DIRECTORY& minidump_directory = minidump_directories[minidump_stream_index];
				MINIDUMP_STREAM_TYPE stream_type = static_cast<MINIDUMP_STREAM_TYPE>(minidump_directory.StreamType);

				if (stream_type == Memory64ListStream)
				{
					minidump_memory64_list_directory = &minidump_directory;
					break;
				}


			}
			ASSERT(minidump_memory64_list_directory != nullptr);
		}

		const MINIDUMP_MEMORY_DESCRIPTOR64* minidump_address_memory64 = nullptr;
		RVA64 minidump_address_memory64_rva = ~RVA64();
		if (minidump_address_memory64 == nullptr)
		{
			const MINIDUMP_MEMORY64_LIST& minidump_memory64_list = *reinterpret_cast<const MINIDUMP_MEMORY64_LIST*>(data + minidump_memory64_list_directory->Location.Rva);
			RVA64 minidump_memory64_rva = minidump_memory64_list.BaseRva;
			for (unsigned long minidump_memory64_index = 0; minidump_memory64_index < minidump_memory64_list.NumberOfMemoryRanges; minidump_memory64_index++)
			{
				const MINIDUMP_MEMORY_DESCRIPTOR64& minidump_memory64 = minidump_memory64_list.MemoryRanges[minidump_memory64_index];

				//console_write_line("0x%llx [0x%llx:0x%llx]", minidump_memory64.StartOfMemoryRange, minidump_memory64_rva, minidump_memory64.DataSize);

				ULONG64 start_of_memory_range = minidump_memory64.StartOfMemoryRange;
				ULONG64 end_of_memory_range = start_of_memory_range + minidump_memory64.DataSize;
				if (address.value() >= minidump_memory64.StartOfMemoryRange && address.value() < end_of_memory_range)
				{
					minidump_address_memory64 = &minidump_memory64;
					minidump_address_memory64_rva = minidump_memory64_rva;
					break;
				}


				minidump_memory64_rva += minidump_memory64.DataSize;
			}
			//ASSERT(minidump_address_memory64 != nullptr);
		}

		if (minidump_address_memory64)
		{
			const char* midnight_image_data = data + minidump_address_memory64_rva;
			ULONG64 rva = address.value() - minidump_address_memory64->StartOfMemoryRange;
			executable_image_data = midnight_image_data + rva;
		}
	}
	else
	{
		ptr32 pa = reach_x360_va_to_pa(address);
		if (~pa != 0)
		{
			executable_image_data = data + pa.value();
		}
	}
	return executable_image_data;
}

std::map<c_reach_x360_tag_group_definition*, std::vector<c_reach_x360_tag_struct_definition*>> struct_definitions;

void reach_x360_sort_structures_struct(c_reach_x360_tag_group_definition& group_definition, c_reach_x360_tag_struct_definition& struct_definition);

void reach_x360_sort_structures_block(c_reach_x360_tag_group_definition& group_definition, c_reach_x360_tag_block_definition& block_definition)
{
	reach_x360_sort_structures_struct(group_definition, block_definition.struct_definition);
}

void reach_x360_sort_structures_array(c_reach_x360_tag_group_definition& group_definition, c_reach_x360_tag_array_definition& array_definition)
{
	reach_x360_sort_structures_struct(group_definition, array_definition.struct_definition);
}

void reach_x360_sort_structures_struct(c_reach_x360_tag_group_definition& group_definition, c_reach_x360_tag_struct_definition& struct_definition)
{
	for (t_reach_x360_tag_field* _field : struct_definition.fields)
	{
		c_reach_x360_tag_field* field = dynamic_cast<c_reach_x360_tag_field*>(_field);
		if (field == nullptr)
		{
			continue;
		}

		if (field->field_type == _reach_x360_field_type_struct)
		{
			ASSERT(field->struct_definition != nullptr);
			reach_x360_sort_structures_struct(group_definition, *field->struct_definition);
		}
		if (field->field_type == _reach_x360_field_type_array)
		{
			ASSERT(field->array_definition != nullptr);
			reach_x360_sort_structures_array(group_definition, *field->array_definition);
		}
		if (field->field_type == _reach_x360_field_type_block)
		{
			ASSERT(field->block_definition != nullptr);
			reach_x360_sort_structures_block(group_definition, *field->block_definition);
		}
	}

	std::vector<c_reach_x360_tag_struct_definition*>& _struct_definitions = struct_definitions[&group_definition];
	_struct_definitions.insert(_struct_definitions.begin(), &struct_definition);
}

void reach_x360_sort_structures(std::vector<c_reach_x360_tag_group_definition*>& group_definitions)
{
	for (auto& group_definition : group_definitions)
	{
		reach_x360_sort_structures_block(*group_definition, *group_definition->tag_block_definition);
	}
}

std::vector<c_reach_x360_tag_resource_definition*> exported_resource_definitions;
void reach_x360_clear_exported_resources()
{
	exported_resource_definitions.clear();
}

bool is_resource_exported(c_reach_x360_tag_resource_definition& resource_definition)
{
	for (c_reach_x360_tag_resource_definition* current_resource_definition : exported_resource_definitions)
	{
		if (current_resource_definition == &resource_definition)
		{
			return true;
		}
	}
	exported_resource_definitions.push_back(&resource_definition);
	return false;
}

std::vector<c_reach_x360_tag_api_interop_definition*> exported_api_interop_definitions;
void reach_x360_clear_exported_api_interops()
{
	exported_api_interop_definitions.clear();
}

bool is_api_interop_exported(c_reach_x360_tag_api_interop_definition& api_interop_definition)
{
	for (c_reach_x360_tag_api_interop_definition* current_api_interop_definition : exported_api_interop_definitions)
	{
		if (current_api_interop_definition == &api_interop_definition)
		{
			return true;
		}
	}
	exported_api_interop_definitions.push_back(&api_interop_definition);
	return false;
}

std::vector<c_reach_x360_tag_data_definition*> exported_data_definitions;
void reach_x360_clear_exported_datas()
{
	exported_data_definitions.clear();
}

bool is_data_exported(c_reach_x360_tag_data_definition& data_definition)
{
	for (c_reach_x360_tag_data_definition* current_data_definition : exported_data_definitions)
	{
		if (current_data_definition == &data_definition)
		{
			return true;
		}
	}
	exported_data_definitions.push_back(&data_definition);
	return false;
}

std::vector<c_reach_x360_tag_struct_definition*> exported_struct_definitions;
void reach_x360_clear_exported_structs()
{
	exported_struct_definitions.clear();
}

bool is_struct_exported(c_reach_x360_tag_struct_definition& struct_definition)
{
	for (c_reach_x360_tag_struct_definition* current_struct_definition : exported_struct_definitions)
	{
		if (current_struct_definition == &struct_definition)
		{
			return true;
		}
	}
	exported_struct_definitions.push_back(&struct_definition);
	return false;
}

std::vector<c_reach_x360_tag_array_definition*> exported_array_definitions;
void reach_x360_clear_exported_arrays()
{
	exported_array_definitions.clear();
}

bool is_array_exported(c_reach_x360_tag_array_definition& array_definition)
{
	for (c_reach_x360_tag_array_definition* current_array_definition : exported_array_definitions)
	{
		if (current_array_definition == &array_definition)
		{
			return true;
		}
	}
	exported_array_definitions.push_back(&array_definition);
	return false;
}

std::vector<c_reach_x360_tag_block_definition*> exported_block_definitions;
void reach_x360_clear_exported_blocks()
{
	exported_block_definitions.clear();
}

bool is_block_exported(c_reach_x360_tag_block_definition& block_definition)
{
	for (c_reach_x360_tag_block_definition* current_block_definition : exported_block_definitions)
	{
		if (current_block_definition == &block_definition)
		{
			return true;
		}
	}
	exported_block_definitions.push_back(&block_definition);
	return false;
}

std::vector<c_reach_x360_tag_group_definition*> exported_group_definitions;
void reach_x360_clear_exported_groups()
{
	exported_group_definitions.clear();
}

bool is_group_exported(c_reach_x360_tag_group_definition& group_definition)
{
	for (c_reach_x360_tag_group_definition* current_group_definition : exported_group_definitions)
	{
		if (current_group_definition == &group_definition)
		{
			return true;
		}
	}
	exported_group_definitions.push_back(&group_definition);
	return false;
}

std::vector<c_reach_x360_tag_reference_definition*> exported_tag_reference_definitions;
void reach_x360_clear_exported_tag_references()
{
	exported_tag_reference_definitions.clear();
}

bool is_tag_reference_exported(c_reach_x360_tag_reference_definition& tag_reference_definition)
{
	for (c_reach_x360_tag_reference_definition* current_tag_reference_definition : exported_tag_reference_definitions)
	{
		if (current_tag_reference_definition == &tag_reference_definition)
		{
			return true;
		}
	}
	exported_tag_reference_definitions.push_back(&tag_reference_definition);
	return false;
}

std::vector<c_reach_x360_string_list_definition*> exported_string_list_definitions;
void reach_x360_clear_exported_string_lists()
{
	exported_string_list_definitions.clear();
}

bool is_string_list_exported(c_reach_x360_string_list_definition& string_list_definition)
{
	for (c_reach_x360_string_list_definition* current_string_list_definition : exported_string_list_definitions)
	{
		if (current_string_list_definition == &string_list_definition)
		{
			return true;
		}
	}
	exported_string_list_definitions.push_back(&string_list_definition);
	return false;
}

std::vector<c_reach_x360_tag_group_definition*> sorted_group_definitions;
c_reach_x360_tag_group_definition* get_sorted_group_definition_by_group_tag(tag group_tag)
{
	for (c_reach_x360_tag_group_definition* current_group_definition : sorted_group_definitions)
	{
		if (current_group_definition->group_tag == group_tag)
		{
			return current_group_definition;
		}
	}
	return nullptr;
}

bool reach_x360_sort_group_definition(c_reach_x360_tag_group_definition& group_definition)
{
	if (!get_sorted_group_definition_by_group_tag(group_definition.group_tag))
	{
		bool include = false;
		include |= group_definition.parent_group_tag == 0xFFFFFFFFu;
		include |= get_sorted_group_definition_by_group_tag(group_definition.parent_group_tag) != nullptr;
		if (include)
		{
			sorted_group_definitions.push_back(&group_definition);
			return true;
		}
	}
	return false;
}

void reach_x360_sort_group_definitions(std::vector<c_reach_x360_tag_group_definition*>& group_definitions)
{
	bool added_structure = false;
	do
	{
		added_structure = false;
		for (c_reach_x360_tag_group_definition* group_definition : group_definitions)
		{
			added_structure |= reach_x360_sort_group_definition(*group_definition);
		}
	} while (added_structure);
}

void reach_x360_generate_tag_field_flags(std::stringstream& s, c_blamlib_string_parser_v2& string_parser)
{
	unsigned long flags_written = 0;

	if (string_parser.flag_unknown0)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_UNKNOWN0";
	}
	if (string_parser.flag_read_only)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_READ_ONLY";
	}
	if (string_parser.flag_index)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_INDEX";
	}
	if (string_parser.flag_unknown3)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_UNKNOWN3";
	}
	if (string_parser.flag_pointer)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_POINTER";
	}

	if (flags_written == 0)
	{
		s << "FIELD_FLAG_NONE";
	}
}

extern void escape_string(
	const char* source,
	char* destination,
	bool remove_return,
	bool unescaped_comma);

extern std::string escape_string(std::string str);

enum e_alt_name_type
{
	_alt_name_type_tag_name,
	_alt_name_type_upgrade_name,
};
struct s_alt_name
{
	e_alt_name_type type;
	const char* string;
};
using t_alt_names = std::vector<s_alt_name>;

void reach_x360_write_alt_names(std::stringstream& s, t_alt_names& alt_names)
{
	s << ", MAKE_ALT_NAMES(";
	t_alt_names::iterator alt_name_iterator = alt_names.begin();
	if (alt_name_iterator != alt_names.end())
	{
		goto first;
		do
		{
			s << ", ";
		first:
			s_alt_name& alt_name = *alt_name_iterator;
			switch (alt_name.type)
			{
			case _alt_name_type_tag_name:
				s << "\"" << alt_name.string << "\"";
				break;
			case _alt_name_type_upgrade_name:
				s << "\"" << alt_name.string << "\"";
				break;
			}
		} while (++alt_name_iterator != alt_names.end());
	}
	s << ")";
}

void reach_x360_write_fields(std::stringstream& s, std::vector<t_reach_x360_tag_field*>& fields)
{
	const char* _namespace = "haloreach";
	command_line_get_argument("blamboozle-haloreach-namespace", _namespace);

	for (auto& _field : fields)
	{
		if (c_reach_x360_tag_field_combined_fixup* combined_fixup_field = dynamic_cast<c_reach_x360_tag_field_combined_fixup*>(_field))
		{
			switch (combined_fixup_field->fixup_type)
			{
			case _reach_x360_tag_field_combined_fixup_type_equal:
				s << "\t\t{ _version_mode_tag_group_equal, &blofeld::" << _namespace << "::" << combined_fixup_field->group_definition.code_name << ", " << combined_fixup_field->count << " }," << std::endl;
				break;
			case _reach_x360_tag_field_combined_fixup_type_not_equal:
				s << "\t\t{ _version_mode_tag_group_not_equal, &blofeld::" << _namespace << "::" << combined_fixup_field->group_definition.code_name << ", " << combined_fixup_field->count << " }," << std::endl;
				break;
			}

			debug_point;
		}
		else if (c_reach_x360_tag_field_dummy_space* dummy_space_field = dynamic_cast<c_reach_x360_tag_field_dummy_space*>(_field))
		{
			s << std::endl;

			debug_point;
		}
		else if (c_reach_x360_tag_field* tag_field = dynamic_cast<c_reach_x360_tag_field*>(_field))
		{

			const char* field_generic_type_name = reach_x360_field_type_to_generic_field_type(tag_field->field_type);

			c_blamlib_string_parser_v2 string_parser = c_blamlib_string_parser_v2(tag_field->name);

			c_fixed_string_4096 pretty_name;
			c_fixed_string_4096 tag_file_name;
			c_fixed_string_4096 description;
			c_fixed_string_4096 units;
			c_fixed_string_4096 limits;
			c_fixed_string_4096 limits_legacy;
			c_fixed_string_4096 old_name;
			c_fixed_string_4096 old_name3;

			if (tag_field->name)
			{
				escape_string(string_parser.pretty_name, pretty_name, true, true);
				escape_string(string_parser.tag_file_name, tag_file_name, true, true);
				escape_string(string_parser.description, description, true, true);
				escape_string(string_parser.units, units, true, true);
				escape_string(string_parser.limits, limits, true, true);
				escape_string(string_parser.limits_legacy, limits_legacy, true, true);
				escape_string(string_parser.old_name, old_name, true, true);
				escape_string(string_parser.old_name3, old_name3, true, true);
			}


			std::vector<s_alt_name> alt_names;
			if (!tag_file_name.empty() && strcmp(pretty_name, tag_file_name) != 0) alt_names.push_back({ _alt_name_type_tag_name, tag_file_name });
			if (!old_name3.empty()) alt_names.push_back({ _alt_name_type_upgrade_name, old_name3 });
			if (!old_name.empty()) alt_names.push_back({ _alt_name_type_upgrade_name, old_name });

			bool write_limits = !limits.empty();
			bool write_units = write_limits || !units.empty();
			bool write_description = write_units || !description.empty();
			bool write_tag_name = strcmp(tag_file_name, pretty_name) != 0;
			bool write_alt_names = !alt_names.empty();
			bool write_flags =
				string_parser.flag_unknown0 ||
				string_parser.flag_read_only ||
				string_parser.flag_index ||
				string_parser.flag_unknown3 ||
				string_parser.flag_pointer;
			bool write_pointer = false; // todo
			bool write_tag = tag_field->field_id != 0;

			if (pretty_name.empty())
			{
				pretty_name = "value";
			}

			switch (tag_field->field_type)
			{
			case _reach_x360_field_type_custom:
			{
				ASSERT(!write_flags);

				if (tag_field->field_id == blofeld::_field_id_field_group_begin)
				{
					ASSERT(!pretty_name.empty());
					ASSERT(description.empty());
					s << "\t\tFIELD_GROUP_BEGIN(";
					if (!pretty_name.empty() && strcmp(pretty_name, "value") != 0) s << "\"" << pretty_name.c_str() << "\"";
					s << ")," << std::endl;
				}
				else if (tag_field->field_id == blofeld::_field_id_field_group_end)
				{
					//ASSERT(pretty_name == "value" || pretty_name.empty());
					ASSERT(description.empty());

					if (pretty_name.empty() || strcmp(pretty_name, "value") == 0) // #TODO: improve this with function
					{
						s << "\t\tFIELD_GROUP_END()," << std::endl;
					}
					else
					{
						s << "\t\tFIELD_GROUP_END2(";
						s << "\"" << pretty_name.c_str() << "\"";
						s << ")," << std::endl;
					}

					//s << "\t\tFIELD_GROUP_END(";
					//if (!pretty_name.empty() && strcmp(pretty_name, "value") != 0) s << "\"" << pretty_name.c_str() << "\"";
					//s << ")," << std::endl;
				}
				else if (tag_field->field_id == blofeld::_field_id_hide_begin)
				{
					ASSERT(pretty_name.empty() || strcmp(pretty_name, "value") == 0);
					ASSERT(description.empty());
					s << "\t\tFIELD_HIDE_BEGIN(";
					if (!pretty_name.empty() && strcmp(pretty_name, "value") != 0) s << "\"" << pretty_name.c_str() << "\"";
					s << ")," << std::endl;
				}
				else if (tag_field->field_id == blofeld::_field_id_hide_end)
				{
					ASSERT(pretty_name.empty() || strcmp(pretty_name, "value") == 0);
					ASSERT(description.empty());
					s << "\t\tFIELD_HIDE_END(";
					if (!pretty_name.empty() && strcmp(pretty_name, "value") != 0) s << "\"" << pretty_name.c_str() << "\"";
					s << ")," << std::endl;
				}
				else if (tag_field->field_id == blofeld::_field_id_ifp_begin)
				{
					ASSERT(pretty_name.empty() || strcmp(pretty_name, "value") == 0);
					ASSERT(description.empty());
					s << "\t\tFIELD_IFP_BEGIN(";
					if (!pretty_name.empty() && strcmp(pretty_name, "value") != 0) s << "\"" << pretty_name.c_str() << "\"";
					s << ")," << std::endl;
				}
				else if (tag_field->field_id == blofeld::_field_id_ifp_end)
				{
					ASSERT(pretty_name.empty() || strcmp(pretty_name, "value") == 0);
					ASSERT(description.empty());
					s << "\t\tFIELD_IFP_END(";
					if (!pretty_name.empty() && strcmp(pretty_name, "value") != 0) s << "\"" << pretty_name.c_str() << "\"";
					s << ")," << std::endl;
				}
				else if (tag_field->field_id == blofeld::_field_id_dont_checksum_begin)
				{
					ASSERT(pretty_name.empty() || strcmp(pretty_name, "value") == 0);
					ASSERT(description.empty());
					s << "\t\tFIELD_DONT_CHECKSUM_BEGIN(";
					if (!pretty_name.empty() && strcmp(pretty_name, "value") != 0) s << "\"" << pretty_name.c_str() << "\"";
					s << ")," << std::endl;
				}
				else if (tag_field->field_id == blofeld::_field_id_dont_checksum_end)
				{
					ASSERT(pretty_name.empty() || strcmp(pretty_name, "value") == 0);
					ASSERT(description.empty());
					s << "\t\tFIELD_DONT_CHECKSUM_END(";
					if (!pretty_name.empty() && strcmp(pretty_name, "value") != 0) s << "\"" << pretty_name.c_str() << "\"";
					s << ")," << std::endl;
				}
				else
				{
					if (description.empty() && !write_flags)
					{
						s << "\t\tFIELD_CUSTOM(";
						if (!pretty_name.empty())
						{
							if (!pretty_name.empty()) s << "\"" << pretty_name.c_str() << "\"";
						}
						s << ", " << (tag_field->field_id_string ? tag_field->field_id_string : "_field_id_default");
						s << ")," << std::endl;
					}
					else
					{
						s << "\t\tFIELD_CUSTOM_EX(";
						if (!pretty_name.empty()) s << "\"" << pretty_name.c_str() << "\"";
						else s << "nullptr";
						if (!description.empty()) s << ", \"" << description.c_str() << "\"";
						else s << ", nullptr";
						s << ", " << (tag_field->field_id_string ? tag_field->field_id_string : "_field_id_default");
						s << ", "; reach_x360_generate_tag_field_flags(s, string_parser);
						s << ")," << std::endl;
					}




				}
				break;
			}
			case _reach_x360_field_type_pad:
			{
				ASSERT(!write_limits);
				ASSERT(!write_units);

				s << "\t\tFIELD_PAD(";
				if (!pretty_name.empty())
				{
					if (!pretty_name.empty()) s << "\"" << pretty_name.c_str() << "\"";
				}
				if (!description.empty())
				{
					if (!description.empty()) s << ", \"" << description.c_str() << "\"";
				}
				s << ", " << tag_field->padding;
				if (write_flags)
				{
					s << ", "; reach_x360_generate_tag_field_flags(s, string_parser);
				}
				s << ")," << std::endl;
			}
			break;
			case _reach_x360_field_type_skip:
			{
				ASSERT(!write_limits);
				ASSERT(!write_units);
				ASSERT(!write_flags);

				s << "\t\tFIELD_SKIP(";
				if (!pretty_name.empty())
				{
					if (!pretty_name.empty()) s << "\"" << pretty_name.c_str() << "\"";
				}
				if (!description.empty())
				{
					if (!description.empty()) s << ", \"" << description.c_str() << "\"";
				}
				s << ", " << tag_field->skip_length;
				if (write_flags)
				{
					s << ", "; reach_x360_generate_tag_field_flags(s, string_parser);
				}
				s << ")," << std::endl;
			}
			break;
			case _reach_x360_field_type_explanation:
			{

				s << "\t\tFIELD_EXPLANATION(";
				if (!pretty_name.empty())
				{
					if (!pretty_name.empty()) s << "\"" << pretty_name.c_str() << "\"";
				}
				if (!description.empty())
				{
					if (!description.empty()) s << ", \"" << description.c_str() << "\"";
				}
				if (tag_field->explanation != nullptr && *tag_field->explanation)
				{
					std::string explanation = escape_string(tag_field->explanation);
					s << ", \"" << explanation << "\"";
				}
				else s << ", nullptr";
				if (write_flags)
				{
					s << ", "; reach_x360_generate_tag_field_flags(s, string_parser);
				}
				s << ")," << std::endl;
			}
			break;
			case _reach_x360_field_type_array:
			{
				s << "\t\t{ ";
				s << field_generic_type_name << ", ";
				s << "\"" << pretty_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_alt_names)
				{
					reach_x360_write_alt_names(s, alt_names);
				}
				if (write_flags)
				{
					s << ", ";
					reach_x360_generate_tag_field_flags(s, string_parser);
				}
				ASSERT(tag_field->array_definition);
				if (tag_field->array_definition)
				{
					s << ", &blofeld::" << _namespace << "::" << tag_field->array_definition->code_name;
				}
				if (write_tag)
				{
					s << ", " << tag_field->field_id_string;
				}

				s << " }," << std::endl;
			}
			break;
			case _reach_x360_field_type_char_block_index:
			case _reach_x360_field_type_short_block_index:
			case _reach_x360_field_type_long_block_index:
			case _reach_x360_field_type_long_block_flags:
			case _reach_x360_field_type_word_block_flags:
			case _reach_x360_field_type_byte_block_flags:
			case _reach_x360_field_type_block:
			{
				s << "\t\t{ ";
				s << field_generic_type_name << ", ";
				s << "\"" << pretty_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_alt_names)
				{
					reach_x360_write_alt_names(s, alt_names);
				}
				if (write_flags)
				{
					s << ", ";
					reach_x360_generate_tag_field_flags(s, string_parser);
				}
				ASSERT(tag_field->block_definition);
				if (tag_field->block_definition)
				{
					s << ", &blofeld::" << _namespace << "::" << tag_field->block_definition->code_name;
				}
				if (write_tag)
				{
					s << ", " << tag_field->field_id_string;
				}

				s << " }," << std::endl;
			}
			break;
			case _reach_x360_field_type_struct:
			{
				s << "\t\t{ ";
				s << field_generic_type_name << ", ";
				s << "\"" << pretty_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_alt_names)
				{
					reach_x360_write_alt_names(s, alt_names);
				}
				if (write_flags)
				{
					s << ", ";
					reach_x360_generate_tag_field_flags(s, string_parser);
				}
				ASSERT(tag_field->struct_definition);
				if (tag_field->struct_definition)
				{
					s << ", &blofeld::" << _namespace << "::" << tag_field->struct_definition->code_name;
				}
				if (write_tag)
				{
					s << ", " << tag_field->field_id_string;
				}

				s << " }," << std::endl;
			}
			break;
			case _reach_x360_field_type_api_interop:
			{
				s << "\t\t{ ";
				s << field_generic_type_name << ", ";
				s << "\"" << pretty_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_alt_names)
				{
					reach_x360_write_alt_names(s, alt_names);
				}
				if (write_flags)
				{
					s << ", ";
					reach_x360_generate_tag_field_flags(s, string_parser);
				}
				ASSERT(tag_field->api_interop_definition);
				if (tag_field->api_interop_definition)
				{
					s << ", &blofeld::" << _namespace << "::" << tag_field->api_interop_definition->code_name;
				}
				if (write_tag)
				{
					s << ", " << tag_field->field_id_string;
				}

				s << " }," << std::endl;
			}
			break;
			case _reach_x360_field_type_data:
			{
				s << "\t\t{ ";
				s << field_generic_type_name << ", ";
				s << "\"" << pretty_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_alt_names)
				{
					reach_x360_write_alt_names(s, alt_names);
				}
				if (write_flags)
				{
					s << ", ";
					reach_x360_generate_tag_field_flags(s, string_parser);
				}
				ASSERT(tag_field->data_definition);
				if (tag_field->data_definition)
				{
					s << ", &blofeld::" << _namespace << "::" << tag_field->data_definition->code_name;
				}
				if (write_tag)
				{
					s << ", " << tag_field->field_id_string;
				}

				s << " }," << std::endl;
			}
			break;
			case _reach_x360_field_type_pageable_resource:
			{
				s << "\t\t{ ";
				s << field_generic_type_name << ", ";
				s << "\"" << pretty_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_alt_names)
				{
					reach_x360_write_alt_names(s, alt_names);
				}
				if (write_flags)
				{
					s << ", ";
					reach_x360_generate_tag_field_flags(s, string_parser);
				}
				ASSERT(tag_field->pageable_resource_definition);
				if (tag_field->pageable_resource_definition)
				{
					s << ", &blofeld::" << _namespace << "::" << tag_field->pageable_resource_definition->code_name;
				}
				if (write_tag)
				{
					s << ", " << tag_field->field_id_string;
				}

				s << " }," << std::endl;
			}
			break;
			case _reach_x360_field_type_tag_reference:
			{
				s << "\t\t{ ";
				s << field_generic_type_name << ", ";
				s << "\"" << pretty_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_alt_names)
				{
					reach_x360_write_alt_names(s, alt_names);
				}
				if (write_flags)
				{
					s << ", ";
					reach_x360_generate_tag_field_flags(s, string_parser);
				}
				ASSERT(tag_field->tag_reference_definition);
				if (tag_field->tag_reference_definition)
				{
					s << ", &blofeld::" << _namespace << "::" << tag_field->tag_reference_definition->code_name;
				}
				if (write_tag)
				{
					s << ", " << tag_field->field_id_string;
				}

				s << " }," << std::endl;
			}
			break;
			case _reach_x360_field_type_terminator:
			{
				s << "\t\t{ _field_terminator }" << std::endl;
			}
			break;
			case _reach_x360_field_type_char_enum:
			case _reach_x360_field_type_short_enum:
			case _reach_x360_field_type_long_enum:
			case _reach_x360_field_type_long_flags:
			case _reach_x360_field_type_word_flags:
			case _reach_x360_field_type_byte_flags:
				s << "\t\t{ ";
				s << field_generic_type_name << ", ";
				s << "\"" << pretty_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_alt_names)
				{
					reach_x360_write_alt_names(s, alt_names);
				}
				if (write_flags)
				{
					s << ", ";
					reach_x360_generate_tag_field_flags(s, string_parser);
				}
				ASSERT(tag_field->string_list_definition);
				if (tag_field->string_list_definition)
				{
					s << ", &blofeld::" << _namespace << "::" << tag_field->string_list_definition->code_name;
				}
				if (write_tag)
				{
					s << ", " << tag_field->field_id_string;
				}

				s << " }," << std::endl;
				break;
			default:
			{
				s << "\t\t{ ";
				s << field_generic_type_name << ", ";
				s << "\"" << pretty_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
					else s << ", " << "nullptr";
				}
				if (write_alt_names)
				{
					reach_x360_write_alt_names(s, alt_names);
				}
				if (write_flags)
				{
					s << ", ";
					reach_x360_generate_tag_field_flags(s, string_parser);
				}
				if (write_pointer) s << ", " << "nullptr";
				if (write_tag)
				{
					s << ", " << tag_field->field_id_string;
				}
				s << " }," << std::endl;
			}
			break;
			}
		}
	}
}

void reach_x360_write_tag_reference_flags(std::stringstream& s, c_reach_x360_tag_reference_definition& tag_reference_definition)
{
	std::stringstream flags_stream;
	if (tag_reference_definition.tag_reference_definition.flags.test(_reach_x360_tag_reference_flag_not_a_dependency))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_not_a_dependency";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_reach_x360_tag_reference_flag_dont_resolve_in_editor))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_dont_resolve_in_editor";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_reach_x360_tag_reference_flag_resolved_manually))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_resolved_manually";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_reach_x360_tag_reference_flag_resolved_by_game))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_resolved_by_game";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_reach_x360_tag_reference_flag_not_a_resource_dependency))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_not_a_resource_dependency";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_reach_x360_tag_reference_flag_dependency_for_cache_file_sharing))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_dependency_for_cache_file_sharing";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_reach_x360_tag_reference_flag_reference_ignored_by_bundle_builder))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_reference_ignored_by_bundle_builder";
	}
	std::string flags_string = flags_stream.str();
	if (!flags_string.empty())
	{
		s << ", " << flags_string;
	}
}

void reach_x360_write_tag_types_header(std::stringstream& s, std::vector<t_reach_x360_tag_field*>& fields)
{
	for (auto& _field : fields)
	{
		if (c_reach_x360_tag_field* tag_field = dynamic_cast<c_reach_x360_tag_field*>(_field))
		{
			switch (tag_field->field_type)
			{
			case _reach_x360_field_type_char_enum:
			case _reach_x360_field_type_short_enum:
			case _reach_x360_field_type_long_enum:
			case _reach_x360_field_type_long_flags:
			case _reach_x360_field_type_word_flags:
			case _reach_x360_field_type_byte_flags:
			{
				ASSERT(tag_field->string_list_definition != nullptr);
				c_reach_x360_string_list_definition& string_list_definition = *tag_field->string_list_definition;
				if (!is_string_list_exported(string_list_definition))
				{
					//s << "\t//extern t_string_list " << string_list_definition.code_name << "_strings;" << std::endl;
					s << "\textern s_string_list_definition " << string_list_definition.code_name << ";" << std::endl;
				}
			}
			break;
			case _reach_x360_field_type_tag_reference:
			{
				ASSERT(tag_field->tag_reference_definition != nullptr);
				c_reach_x360_tag_reference_definition& tag_reference_definition = *tag_field->tag_reference_definition;
				if (!is_tag_reference_exported(tag_reference_definition))
				{
					s << "\textern s_tag_reference_definition " << tag_reference_definition.code_name << ";";

					s << std::endl;
				}
			}
			break;
			}
		}
	}
}

void reach_x360_write_tag_types_source(std::stringstream& s, std::vector<t_reach_x360_tag_field*>& fields)
{
	for (auto& _field : fields)
	{
		if (c_reach_x360_tag_field_combined_fixup* combined_fixup_field = dynamic_cast<c_reach_x360_tag_field_combined_fixup*>(_field))
		{

		}
		else if (c_reach_x360_tag_field* tag_field = dynamic_cast<c_reach_x360_tag_field*>(_field))
		{
			switch (tag_field->field_type)
			{
			case _reach_x360_field_type_char_enum:
			case _reach_x360_field_type_short_enum:
			case _reach_x360_field_type_long_enum:
			case _reach_x360_field_type_long_flags:
			case _reach_x360_field_type_word_flags:
			case _reach_x360_field_type_byte_flags:
			{
				ASSERT(tag_field->string_list_definition != nullptr);
				c_reach_x360_string_list_definition& string_list_definition = *tag_field->string_list_definition;
				if (!is_string_list_exported(string_list_definition))
				{
					if (string_list_definition.options.size() > 0)
					{
						s << "\tSTRINGS(" << string_list_definition.code_name << ")" << std::endl;
						s << "\t{" << std::endl;
						for (unsigned long i = 0; i < string_list_definition.options.size(); i++)
						{
							const char* option = string_list_definition.options[i];
							std::string escaped_option = escape_string(option);
							if (escaped_option.empty()) escaped_option = "unused";
							if (i != string_list_definition.options.size() - 1)
							{
								s << "\t\t\"" << escaped_option << "\"," << std::endl;
							}
							else
							{
								s << "\t\t\"" << escaped_option << "\"" << std::endl;
							}
						}
						s << "\t};" << std::endl;

						s << "\tSTRING_LIST(" << string_list_definition.code_name << ", " << string_list_definition.code_name << "_strings, _countof(" << string_list_definition.code_name << "_strings));" << std::endl;
					}
					else
					{
						s << "\tSTRING_LIST(" << string_list_definition.code_name << ", empty_string_list, 0);" << std::endl;
					}

					s << std::endl;
				}
			}
			break;
			case _reach_x360_field_type_tag_reference:
			{
				ASSERT(tag_field->tag_reference_definition != nullptr);
				c_reach_x360_tag_reference_definition& tag_reference_definition = *tag_field->tag_reference_definition;
				if (!is_tag_reference_exported(tag_reference_definition))
				{
					if (tag_reference_definition.group_tags.size() > 1)
					{
						s << "\tTAG_REFERENCE_GROUP(" << tag_reference_definition.code_name;
						reach_x360_write_tag_reference_flags(s, tag_reference_definition);
						s << ")" << std::endl;
						s << "\t{" << std::endl;
						bool first = true;
						for (c_reach_x360_tag_group_definition* group_definition : tag_reference_definition.group_tags2)
						{
							s << "\t\t" << group_definition->tag_symbol_name << "," << std::endl;
							first = false;
						}
						s << "\t\tINVALID_TAG" << std::endl;

						s << "\t};" << std::endl;
					}
					else if (tag_reference_definition.group_tags.size() == 1)
					{
						s << "\tTAG_REFERENCE(" << tag_reference_definition.code_name << ", " << tag_reference_definition.group_tags2[0]->tag_symbol_name;
						reach_x360_write_tag_reference_flags(s, tag_reference_definition);
						s << ");" << std::endl;
					}
					else
					{
						s << "\tTAG_REFERENCE(" << tag_reference_definition.code_name << ", INVALID_TAG";
						reach_x360_write_tag_reference_flags(s, tag_reference_definition);
						s << ");" << std::endl;
					}

					s << std::endl;
				}
			}
			break;
			}
		}
	}
}

void reach_x360_export_header(
	std::stringstream& s,
	std::vector<c_reach_x360_tag_group_definition*>& group_definitions,
	std::vector<c_reach_x360_tag_block_definition*>& block_definitions,
	std::vector<c_reach_x360_tag_array_definition*>& array_definitions,
	std::vector<c_reach_x360_tag_struct_definition*>& struct_definitions,
	std::vector<c_reach_x360_tag_data_definition*>& data_definitions,
	std::vector<c_reach_x360_tag_resource_definition*>& resource_definitions,
	std::vector<c_reach_x360_tag_api_interop_definition*>& api_interop_definitions)
{
	reach_x360_clear_exported_resources();
	reach_x360_clear_exported_api_interops();
	reach_x360_clear_exported_datas();
	reach_x360_clear_exported_structs();
	reach_x360_clear_exported_groups();
	reach_x360_clear_exported_blocks();
	reach_x360_clear_exported_arrays();
	reach_x360_clear_exported_tag_references();
	reach_x360_clear_exported_string_lists();

	const char* _namespace = "haloreach";
	command_line_get_argument("blamboozle-haloreach-namespace", _namespace);

	s << "#pragma once" << std::endl;
	s << std::endl;
	s << "namespace blofeld" << std::endl;
	s << "{" << std::endl;
	s << "namespace " << _namespace << " {" << std::endl;
	s << std::endl;

	for (auto& group_definition : group_definitions)
	{
		if (!is_group_exported(*group_definition))
		{
			union
			{
				unsigned long long _byteswap_group_tag;
				char _group_tag_str[sizeof(_byteswap_group_tag)];
			};
			_byteswap_group_tag = _byteswap_ulong(group_definition->group_tag);
			const char* group_tag_string = _group_tag_str;
			while (*group_tag_string == 0)
			{
				group_tag_string++;
			}

			s << "\tstatic constexpr unsigned long " << group_definition->tag_symbol_name << " = '" << group_tag_string << "';" << std::endl;
			s << "\textern s_tag_group " << group_definition->code_name << ";" << std::endl;
			//s << "\textern s_tag_group " << group_definition->pretty_name << "_group;" << std::endl;

			s << std::endl;
		}
	}
	for (auto& block_definition : block_definitions)
	{
		if (!is_block_exported(*block_definition))
		{
			s << "\textern s_tag_block_definition " << block_definition->code_name << ";" << std::endl;

			s << std::endl;
		}
	}
	for (auto& array_definition : array_definitions)
	{
		if (!is_array_exported(*array_definition))
		{
			s << "\textern s_tag_array_definition " << array_definition->code_name << ";" << std::endl;

			s << std::endl;
		}
	}
	for (auto& struct_definition : struct_definitions)
	{
		if (!is_struct_exported(*struct_definition))
		{
			s << "\textern s_tag_struct_definition " << struct_definition->code_name << ";" << std::endl;

			reach_x360_write_tag_types_header(s, struct_definition->fields);

			s << std::endl;
		}
	}

	for (auto& data_definition : data_definitions)
	{
		if (!is_data_exported(*data_definition))
		{
			s << "\textern s_tag_data_definition " << data_definition->code_name << ";" << std::endl;

			s << std::endl;
		}
	}

	for (auto& resource_definition : resource_definitions)
	{
		if (!is_resource_exported(*resource_definition))
		{
			s << "\textern s_tag_resource_definition " << resource_definition->code_name << ";" << std::endl;

			s << std::endl;
		}
	}

	for (auto& api_interop_definition : api_interop_definitions)
	{
		if (!is_api_interop_exported(*api_interop_definition))
		{
			s << "\textern s_tag_interop_definition " << api_interop_definition->code_name << ";" << std::endl;

			s << std::endl;
		}
	}

	s << std::endl;
	s << "} // namespace blofeld" << std::endl;
	s << std::endl;
	s << "} // namespace haloreach" << std::endl;
	s << std::endl;
}

static const char* reach_tag_field_set_bit_to_field_set_bit_macro(e_reach_tag_field_set_bit runtime_flag)
{
	switch (runtime_flag)
	{
	case _reach_tag_field_set_unknown0:										return "SET_UNKNOWN0";
	case _reach_tag_field_set_unknown1:										return "SET_UNKNOWN1";
	case _reach_tag_field_set_has_inlined_children_with_placement_new_bit:	return "SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW";
	case _reach_tag_field_set_unknown3:										return "SET_UNKNOWN3";
	case _reach_tag_field_set_unknown4:										return "SET_UNKNOWN4";
	case _reach_tag_field_set_unknown5:										return "SET_UNKNOWN5";
	case _reach_tag_field_set_is_temporary_bit:								return "SET_IS_TEMPORARY";
	case _reach_tag_field_set_unknown7:										return "SET_UNKNOWN7";
	case _reach_tag_field_set_unknown8:										return "SET_UNKNOWN8";
	case _reach_tag_field_set_delete_recursively_bit:						return "SET_DELETE_RECURSIVELY";
	case _reach_tag_field_set_postprocess_recursively_bit:					return "SET_POSTPROCESS_RECURSIVELY";
	case _reach_tag_field_set_is_memcpyable_bit:							return "SET_IS_MEMCPYABLE";
	case _reach_tag_field_set_unknown12:									return "SET_UNKNOWN12";
	case _reach_tag_field_set_has_resources:								return "SET_HAS_RESOURCES";
	case _reach_tag_field_set_unknown14:									return "SET_UNKNOWN14";
	case _reach_tag_field_set_unknown15:									return "SET_UNKNOWN15";
	case _reach_tag_field_set_has_level_specific_fields_bit:				return "SET_HAS_LEVEL_SPECIFIC_FIELDS";
	case _reach_tag_field_set_can_memset_to_initialize_bit:					return "SET_CAN_MEMSET_TO_INITIALIZE";
	case _reach_tag_field_set_unknown18:									return "SET_UNKNOWN18";
	case _reach_tag_field_set_unknown19:									return "SET_UNKNOWN19";
	}
	throw;
}

void reach_x360_export_source(
	std::stringstream& s,
	std::vector<c_reach_x360_tag_group_definition*>& group_definitions,
	std::vector<c_reach_x360_tag_block_definition*>& block_definitions,
	std::vector<c_reach_x360_tag_array_definition*>& array_definitions,
	std::vector<c_reach_x360_tag_struct_definition*>& struct_definitions,
	std::vector<c_reach_x360_tag_data_definition*>& data_definitions,
	std::vector<c_reach_x360_tag_resource_definition*>& resource_definitions,
	std::vector<c_reach_x360_tag_api_interop_definition*>& api_interop_definitions)
{
	reach_x360_clear_exported_resources();
	reach_x360_clear_exported_api_interops();
	reach_x360_clear_exported_datas();
	reach_x360_clear_exported_structs();
	reach_x360_clear_exported_groups();
	reach_x360_clear_exported_blocks();
	reach_x360_clear_exported_arrays();
	reach_x360_clear_exported_tag_references();
	reach_x360_clear_exported_string_lists();

	const char* _namespace = "haloreach";
	command_line_get_argument("blamboozle-haloreach-namespace", _namespace);

	s << "#include <tagdefinitions-private-pch.h>" << std::endl;
	s << "#include <blofeld_field_type_override.h>" << std::endl;
	s << std::endl;
	s << "namespace blofeld" << std::endl;
	s << "{" << std::endl;
	s << "namespace " << _namespace << " {" << std::endl;
	s << std::endl;

	for (auto& group_definition : group_definitions)
	{
		if (!is_group_exported(*group_definition))
		{
			c_reach_x360_tag_block_definition* block_definition = group_definition->tag_block_definition;
			c_reach_x360_tag_struct_definition* struct_definition = &block_definition->struct_definition;

			s << "\tTAG_GROUP_V2(" << std::endl;
			s << "\t\t\"" << group_definition->name << "\"," << std::endl;
			s << "\t\t" << group_definition->code_name << "," << std::endl;
			s << "\t\t" << group_definition->tag_symbol_name.c_str() << "," << std::endl;
			if (c_reach_x360_tag_group_definition* parent_group_definition = get_sorted_group_definition_by_group_tag(group_definition->parent_group_tag))
			{
				s << "\t\t&" << parent_group_definition->code_name << "," << std::endl;
				//s << "\t\t&" << parent_group_definition->pretty_name << "_group," << std::endl;
				s << "\t\t" << parent_group_definition->tag_symbol_name.c_str() << "," << std::endl;
			}
			else
			{
				s << "\t\t" << "nullptr," << std::endl;
				s << "\t\t" << "INVALID_TAG," << std::endl;
			}
			s << "\t\t" << block_definition->code_name << ");" << std::endl;
			s << std::endl;
		}
	}
	for (auto& block_definition : block_definitions)
	{
		if (!is_block_exported(*block_definition))
		{
			c_reach_x360_tag_struct_definition* struct_definition = &block_definition->struct_definition;

			if (strcmp(block_definition->pretty_name.c_str(), "multilingual_unicode_string_list_block") == 0)
			{
				debug_point;
			}

			s << "\tTAG_BLOCK_FROM_STRUCT_V2(" << std::endl;
			s << "\t\t" << block_definition->code_name << "," << std::endl;
			s << "\t\t" << "\"" << block_definition->pretty_name << "\"," << std::endl;
			s << "\t\t" << "\"" << block_definition->name << "\"," << std::endl;
			s << "\t\t" << "" << block_definition->max_count << "," << std::endl;
			s << "\t\t" << struct_definition->code_name << ");" << std::endl;
			s << std::endl;
		}
	}
	for (auto& array_definition : array_definitions)
	{
		if (!is_array_exported(*array_definition))
		{
			c_reach_x360_tag_struct_definition* struct_definition = &array_definition->struct_definition;

			s << "\tTAG_ARRAY_FROM_STRUCT(" << std::endl;
			s << "\t\t" << array_definition->code_name << "," << std::endl;
			s << "\t\t" << "\"" << array_definition->name << "\"," << std::endl;
			s << "\t\t" << "" << array_definition->count << "," << std::endl;
			s << "\t\t" << struct_definition->code_name << ");" << std::endl;
			s << std::endl;
		}
	}
	for (auto& struct_definition : struct_definitions)
	{
		if (!is_struct_exported(*struct_definition))
		{
			char persistent_identifier_buffer[256];
			snprintf(
				persistent_identifier_buffer,
				256,
				"0x%08X, 0x%08X, 0x%08X, 0x%08X",
				struct_definition->persistent_identifier.identifier_part_0,
				struct_definition->persistent_identifier.identifier_part_1,
				struct_definition->persistent_identifier.identifier_part_2,
				struct_definition->persistent_identifier.identifier_part_3);

			char persistent_identifier_name_buffer[256];
			snprintf(
				persistent_identifier_name_buffer,
				256,
				"%s_id",
				struct_definition->code_name.c_str());
			for (char* persistent_identifier_name_pos = persistent_identifier_name_buffer; *persistent_identifier_name_pos; persistent_identifier_name_pos++)
			{
				*persistent_identifier_name_pos = toupper(*persistent_identifier_name_pos);
			}

			//std::string runtime_flags = create_struct_definition_runtime_flags(tag_struct.runtime_flags, "\n\t\t");
			//std::string memory_attributes = create_struct_definition_memory_attributes(tag_struct.memory_attributes.memory_type, tag_struct.memory_attributes.usage_flags, "\n\t\t");

			s << "\t#define " << persistent_identifier_name_buffer << " { " << persistent_identifier_buffer << " }" << std::nouppercase << std::endl;

			s << "\tTAG_STRUCT(" << std::endl;
			s << "\t\t" << struct_definition->code_name << "," << std::endl;
			s << "\t\t" << "\"" << struct_definition->pretty_name << "\"," << std::endl;
			s << "\t\t" << "\"" << struct_definition->name << "\"," << std::endl;
			s << "\t\t" << "\"s_" << struct_definition->code_name << "\"," << std::endl;

			c_flags<e_reach_tag_field_set_bit, long, k_num_reach_runtime_flags> default_flags;
			default_flags.set(_reach_tag_field_set_unknown0, true);
			default_flags.set(_reach_tag_field_set_unknown1, true);
			default_flags.set(_reach_tag_field_set_unknown5, true);
			default_flags.set(_reach_tag_field_set_delete_recursively_bit, true);
			default_flags.set(_reach_tag_field_set_postprocess_recursively_bit, true);
			
			if (struct_definition->struct_definitions.front().first.runtime.flags == default_flags)
			{
				s << "\t\t" << "SET_DEFAULT," << std::endl;
			}
			else
			{
				s << "\t\t";
				bool is_first = true;
				for (long _reach_tag_field_set = 0; _reach_tag_field_set < k_num_reach_runtime_flags; _reach_tag_field_set++)
				{
					e_reach_tag_field_set_bit reach_tag_field_set = static_cast<e_reach_tag_field_set_bit>(_reach_tag_field_set);
					if (struct_definition->struct_definitions.front().first.runtime.flags.test(reach_tag_field_set))
					{
						const char* macro = reach_tag_field_set_bit_to_field_set_bit_macro(reach_tag_field_set);

						if (!is_first)
						{
							s << " | ";
						}

						s << macro;

						is_first = false;
					}
				}
				s << "," << std::endl;
			}
			s << "\t\t" << "TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY)," << std::endl;
			s << "\t\t" << persistent_identifier_name_buffer;
			if (struct_definition->alignment_bits)
			{
				s << "," << std::endl;
				s << "\t\t" << struct_definition->alignment_bits;
			}
			s << ")" << std::endl;
			s << "\t" << "{" << std::endl;
			reach_x360_write_fields(s, struct_definition->fields);
			s << "\t" << "};" << std::endl;
			s << std::endl;

			reach_x360_write_tag_types_source(s, struct_definition->fields);
		}

	}
	for (auto& data_definition : data_definitions)
	{
		if (!is_data_exported(*data_definition))
		{
			s << "\tTAG_DATA(" << std::endl;
			s << "\t\t" << data_definition->code_name << "," << std::endl;
			s << "\t\t" << "\"" << data_definition->name << "\"," << std::endl;
			s << "\t\t" << "" << data_definition->flags << "," << std::endl;
			s << "\t\t" << "" << data_definition->alignment_bit << "," << std::endl;
			s << "\t\t" << "" << data_definition->maximum_size << "," << std::endl;
			s << "\t\t" << "" << data_definition->maximum_size_string << ");" << std::endl;
			s << std::endl;
		}
	}

	for (auto& resource_definition : resource_definitions)
	{
		if (!is_resource_exported(*resource_definition))
		{
			s << "\tTAG_RESOURCE(" << std::endl;
			s << "\t\t" << resource_definition->code_name << "," << std::endl;
			s << "\t\t" << "\"" << resource_definition->name << "\"," << std::endl;
			s << "\t\t" << resource_definition->struct_definition.code_name << ");" << std::endl;
			s << std::endl;
		}
	}

	for (auto& api_interop_definition : api_interop_definitions)
	{
		if (!is_api_interop_exported(*api_interop_definition))
		{
			char persistent_identifier_buffer[256];
			snprintf(
				persistent_identifier_buffer,
				256,
				"0x%08X, 0x%08X, 0x%08X, 0x%08X",
				api_interop_definition->persistent_identifier.identifier_part_0,
				api_interop_definition->persistent_identifier.identifier_part_1,
				api_interop_definition->persistent_identifier.identifier_part_2,
				api_interop_definition->persistent_identifier.identifier_part_3);

			char persistent_identifier_name_buffer[256];
			snprintf(
				persistent_identifier_name_buffer,
				256,
				"%s_id",
				api_interop_definition->code_name.c_str());
			for (char* persistent_identifier_name_pos = persistent_identifier_name_buffer; *persistent_identifier_name_pos; persistent_identifier_name_pos++)
			{
				*persistent_identifier_name_pos = toupper(*persistent_identifier_name_pos);
			}

			s << "\t#define " << persistent_identifier_name_buffer << " { " << persistent_identifier_buffer << " }" << std::nouppercase << std::endl;

			s << "\tTAG_INTEROP(" << std::endl;
			s << "\t\t" << api_interop_definition->code_name << "," << std::endl;
			s << "\t\t" << "\"" << api_interop_definition->name << "\"," << std::endl;
			s << "\t\t" << api_interop_definition->struct_definition.code_name << "," << std::endl;
			s << "\t\t" << persistent_identifier_name_buffer << ");" << std::endl;
			s << std::endl;
		}
	}

	s << std::endl;
	s << "} // namespace blofeld" << std::endl;
	s << std::endl;
	s << "} // namespace haloreach" << std::endl;
	s << std::endl;
}

void reach_x360_export_code(
	std::vector<c_reach_x360_tag_group_definition*>& group_definitions,
	std::vector<c_reach_x360_tag_block_definition*>& block_definitions,
	std::vector<c_reach_x360_tag_array_definition*>& array_definitions,
	std::vector<c_reach_x360_tag_struct_definition*>& struct_definitions,
	std::vector<c_reach_x360_tag_data_definition*>& data_definitions,
	std::vector<c_reach_x360_tag_resource_definition*>& resource_definitions,
	std::vector<c_reach_x360_tag_api_interop_definition*>& api_interop_definitions)
{
	std::stringstream header_stream;
	std::stringstream source_stream;

	reach_x360_sort_group_definitions(group_definitions);
	reach_x360_sort_structures(sorted_group_definitions);

	reach_x360_export_header(header_stream, sorted_group_definitions, block_definitions, array_definitions, struct_definitions, data_definitions, resource_definitions, api_interop_definitions);
	reach_x360_export_source(source_stream, sorted_group_definitions, block_definitions, array_definitions, struct_definitions, data_definitions, resource_definitions, api_interop_definitions);

	std::string header_string = header_stream.str();
	std::string source_string = source_stream.str();

	const char* header_filename = "haloreach.h";
	command_line_get_argument("blamboozle-haloreach-header-filename", header_filename);

	const char* source_filename = "haloreach.cpp";
	command_line_get_argument("blamboozle-haloreach-source-filename", source_filename);

	const char* output_directory;
	ASSERT(BCS_SUCCEEDED(command_line_get_argument("blamboozle-output", output_directory)));
	std::string source_output_filepath = std::string(output_directory) + source_filename;
	std::string header_output_filepath = std::string(output_directory) + header_filename;

	BCS_RESULT macaque_header_write_file_result = filesystem_write_file_from_memory(header_output_filepath.c_str(), header_string.c_str(), header_string.size());
	ASSERT(BCS_SUCCEEDED(macaque_header_write_file_result));

	BCS_RESULT macaque_header_write_file_result2 = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_string.c_str(), source_string.size());
	ASSERT(BCS_SUCCEEDED(macaque_header_write_file_result2));
}


std::string reach_x360_convert_to_code_name(std::string name)
{
	c_fixed_string_1024 str = name.c_str();
	str.lowercase();
	str.replace(' ', '_');
	str.replace('/', '_');
	str.replace('\\', '_');
	str.replace('-', '_');
	str.replace('+', '_');
	str.replace('&', '_');
	str.replace('|', '_');
	str.replace('>', '_');
	str.replace('<', '_');
	str.replace('=', '_');
	str.remove('*');
	str.remove('{');
	str.remove('}');
	str.remove('@');
	str.remove('(');
	str.remove(')');
	str.remove('.');
	str.remove(',');
	str.remove('\'');
	str.remove(':');
	str.remove(';');
	str.remove('\"');

	return str.c_str();
}