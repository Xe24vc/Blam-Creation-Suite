#pragma once

struct s_tag_block_chunk_header
{
	unsigned long count;
	unsigned long is_simple_data_type;
};

class c_single_tag_file_reader;
struct s_tag_persist_block_definition;
struct s_tag_persist_struct_definition;

class c_tag_block_chunk : public c_typed_chunk<'tgbl', true>
{
public:
	const char* block_structure_data_begin;
	const char* block_structure_data_position;
	const char* block_child_chunk_data_start;
	const char* block_child_chunk_data_position;
	s_tag_persist_block_definition* block_entry;
	s_tag_persist_struct_definition* structure_entry;
	unsigned long structure_index;
	s_tag_block_chunk_header tag_block_chunk_header;
	unsigned long block_data_size;
	unsigned long struct_size;
	DEBUG_ONLY(unsigned long debug_stack_length_start);

	c_tag_block_chunk(c_chunk& parent);
	~c_tag_block_chunk();
	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;
	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;

	const char* get_sturcutre_data_by_index(unsigned long index) const;
	c_tag_struct_chunk* get_sturcutre_chunk_by_index(unsigned long index) const;

	void read_tag_block_structures(c_single_tag_file_reader& reader) const;
	void read_structure_metadata(
		c_single_tag_file_reader& reader,
		s_tag_persist_struct_definition& structure_entry,
		t_tag_file_reader_metadata_stack& metadata_stack) const;
	void read_structure_data(c_single_tag_file_reader& reader, s_tag_persist_struct_definition& structure_entry, const char* structure_data_pos, c_tag_struct_chunk* tag_struct_chunk);

};
