#include "halo3tagfiletest-private-pch.h"

c_tag_layout_v3_chunk::c_tag_layout_v3_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent)
{
	debug_point;

	parse_children(nullptr);
}