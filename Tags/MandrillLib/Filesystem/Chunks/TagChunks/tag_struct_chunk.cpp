#include "mandrilllib-private-pch.h"

c_tag_struct_chunk::c_tag_struct_chunk(c_chunk& parent) :
	c_typed_chunk(&parent)
{
	

	debug_point;

	log_pad();
	log_signature();
	console_end_line_verbose();
}

void c_tag_struct_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	if (!debug_string.empty())
	{
		console_write_line_verbose("metadata:0x%08lu chunk_size:0x%08lu debug_string:%s 0x%p", metadata, chunk_size, debug_string.c_str(), this);
	}
	else
	{
		console_write_line_verbose("metadata:0x%08lu chunk_size:0x%08lu", metadata, chunk_size);
	}
}
