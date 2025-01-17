#pragma once

#pragma pack(push, 1)
struct s_symbol_file_public
{
	union
	{
		uintptr_t symbol_name_offset;
		const char* symbol_name;
	};
	union
	{
		uintptr_t mangled_symbol_name_offset;
		const char* mangled_symbol_name;
	};
	union
	{
		uintptr_t lib_and_object_offset;
		const char* lib_and_object;
	};
#ifndef _DEBUG
	union
	{
		uintptr_t complete_symbol_name_offset;
		const char* complete_symbol_name;
	};
#endif

	unsigned long rva;
	union
	{
		unsigned short section_index;
		struct
		{
			unsigned long long : 16;
			unsigned long long rva_plus_base : 48;
		};
	};
};
#pragma pack(pop)
