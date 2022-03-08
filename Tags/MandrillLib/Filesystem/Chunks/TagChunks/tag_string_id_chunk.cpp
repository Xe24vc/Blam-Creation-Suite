#include "mandrilllib-private-pch.h"

c_tag_string_id_chunk::c_tag_string_id_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	string()
{
	debug_point;

	log_pad();
	log_signature();
	console_write_line_verbose("'%s'", string);
}

c_tag_string_id_chunk::~c_tag_string_id_chunk()
{
	delete[] string;
}

BCS_RESULT c_tag_string_id_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	const char* chunk_data_start = get_chunk_data_start();
	intptr_t string_length = chunk_size;
	char* string_buffer = new() char[string_length + 1];
	memcpy(string_buffer, chunk_data_start, string_length);
	string_buffer[string_length] = 0;

	string = string_buffer;

	return rs;
}

void c_tag_string_id_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("'%s'", string);
}
