#include "tagdefinitions-private-pch.h"

blofeld::s_block_index_custom_search_definition::s_block_index_custom_search_definition(
	const char* name,
	const char* symbol_name,
	const char* filename,
	int line) :
	name(name),
	symbol_name(symbol_name),
	filename(filename),
	line(line)
{
	symbol_manager_get_public_symbol_by_pointer(this, symbol);
}
