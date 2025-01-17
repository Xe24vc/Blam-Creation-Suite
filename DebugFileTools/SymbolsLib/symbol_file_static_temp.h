#pragma once

struct s_symbol_file_static_temp
{
	unsigned long section_index;
	unsigned long rva;
	unsigned long long rva_plus_base;
	char lib_and_object[256];

	char symbol_name[1024];
#ifndef _DEBUG
	char complete_symbol_name[1536];
#endif
	char mangled_symbol_name_buffer[1024];

	s_symbol_file_static* static_symbol;
};
