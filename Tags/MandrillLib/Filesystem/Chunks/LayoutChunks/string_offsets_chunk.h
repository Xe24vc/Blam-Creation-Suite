#pragma once

struct s_tag_persist_string_character_index
{
	unsigned long offset;
};

class c_string_offsets_chunk : public c_typed_chunk<'sz+x', false>
{
public:
	s_tag_persist_string_character_index* offsets;
	unsigned long entry_count;

	c_string_offsets_chunk(c_chunk& parent);
	~c_string_offsets_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);

	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;

};
