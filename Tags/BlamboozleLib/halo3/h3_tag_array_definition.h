#pragma once

class c_h3_tag_struct_definition;
class c_h3_tag_group_definition;

struct s_h3_tag_array_definition
{
	ptr64 name_address;
	unsigned long element_count;
	unsigned long padding;
	ptr64 element_count_string;
	ptr64 structure_definition_address;
};
constexpr size_t k_h3_tag_array_definition_size = sizeof(s_h3_tag_array_definition);
static_assert(k_h3_tag_array_definition_size == 32);

class c_h3_tag_array_definition
{
public:
	std::string name;
	std::string code_name;
	unsigned long count;
	const s_h3_tag_array_definition& array_definition;
	c_h3_tag_struct_definition& struct_definition;

	c_h3_tag_array_definition(const char* guerilla_data, const s_h3_tag_array_definition& definition_header);

	static std::map<ptr64, c_h3_tag_array_definition*> tag_array_definitions;
	static c_h3_tag_array_definition* h3_get_tag_array_definition(const char* guerilla_data, ptr64 virtual_address);
};

