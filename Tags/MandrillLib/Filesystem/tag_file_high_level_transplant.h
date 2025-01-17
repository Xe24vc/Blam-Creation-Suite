#pragma once

struct s_single_tag_file_header;
class c_single_tag_file_reader;
class c_single_tag_file_layout_reader;
class c_chunk;
class c_tag_group_layout_chunk;
class c_binary_data_chunk;

class c_tag_file_high_level_transplant
{
public:
	void* tag_file_data;
	unsigned long long tag_file_data_size;

	s_single_tag_file_header* header_data;
	c_single_tag_file_layout_reader* layout_reader;
	c_single_tag_file_reader* reader;

	s_engine_platform_build engine_platform_build;

	BCS_DEBUG_API c_tag_file_high_level_transplant(const char* filepath, s_engine_platform_build engine_platform_build);
	BCS_DEBUG_API ~c_tag_file_high_level_transplant();
	BCS_DEBUG_API h_tag* parse_tag();
};

