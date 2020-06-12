#pragma once
class c_halo3_cache_file :
	public c_cache_file
{
	friend c_cache_file;
protected:
	bool read_cache_file();
	c_halo3_cache_file(const std::wstring& map_filepath);
	virtual ~c_halo3_cache_file();

public:
	virtual bool save_map() final;
	virtual bool is_loading() const final;
	virtual uint64_t get_base_virtual_address() const final;
	virtual uint64_t convert_page_offset(uint64_t page_offset) const final;
	virtual uint32_t get_tag_count() const final;
	virtual uint32_t get_tag_group_count() const final;
	virtual uint32_t get_string_id_count() const final;
	virtual char* get_tag_data(s_tag_data& tag_data) const final;
	virtual char* get_tag_block_data(s_tag_block& tag_block) const final;
	virtual const char* get_string_id_by_index(uint32_t index) const final;
	virtual const char* get_string_id(string_id const id, const char* const error_value = nullptr) const final;
	virtual const char* get_tag_path(uint16_t tag_index) const final;
	virtual unsigned long get_group_tag_by_tag_index(uint32_t tag_index) const final;
	virtual void get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const final;

	virtual const s_section_cache* get_section(uint32_t section_index) const final;

	inline gen3::s_cache_file_tag_instance& get_internal_tag_instance(uint16_t tag_index) const 
	{ 
		gen3::s_cache_file_tag_instance* tag_instance = reinterpret_cast<gen3::s_cache_file_tag_instance*>(get_internal_tag_instance_impl(tag_index));
		DEBUG_ASSERT(tag_instance != nullptr);
		return *tag_instance;
	};
	inline gen3::s_cache_file_tag_group& get_internal_tag_group(uint32_t group_index) const
	{
		gen3::s_cache_file_tag_group* tag_group = reinterpret_cast<gen3::s_cache_file_tag_group*>(get_internal_tag_group_impl(group_index));
		DEBUG_ASSERT(tag_group != nullptr);
		return *tag_group;
	};

protected:
	virtual void* get_internal_tag_instance_impl(uint16_t tag_index) const final;
	virtual void* get_internal_tag_group_impl(uint32_t group_index) const final;

	halo3::s_cache_file_header* cache_file_header;
	halo3::s_cache_file_tags_header* cache_file_tags_header;
	gen3::s_cache_file_tag_group* cache_file_tag_groups;
	gen3::s_cache_file_tag_instance* cache_file_tag_instances;
	char* string_ids_buffer;
	long* string_id_indices;
	char* filenames_buffer;
	long* filename_indices;
	char* tags_buffer;
};

