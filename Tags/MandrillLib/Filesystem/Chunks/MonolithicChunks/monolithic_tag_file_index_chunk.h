#pragma once

class c_monolithic_tag_file_index_chunk : public c_typed_chunk<'mtfi', true>
{
public:
	c_monolithic_tag_file_index_chunk(c_chunk& parent);
};
