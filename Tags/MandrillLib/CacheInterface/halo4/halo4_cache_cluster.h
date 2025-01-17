#pragma once

class c_halo4_debug_reader;
class c_halo4_tag_reader;
class c_halo4_resource_reader;
class c_halo4_localization_reader;
class c_halo4_tag_group;
class c_halo4_tag_instance;

class c_halo4_cache_cluster : public c_cache_cluster
{
public:
	friend c_debug_reader;
	friend c_tag_reader;
	friend c_resource_reader;
	friend c_localization_reader;
	friend c_halo4_debug_reader;
	friend c_halo4_tag_reader;
	friend c_halo4_resource_reader;
	friend c_halo4_localization_reader;
	friend c_halo4_tag_group;
	friend c_halo4_tag_instance;

	c_halo4_cache_cluster(c_halo4_cache_file_reader** cache_readers, unsigned long cache_reader_count, s_engine_platform_build engine_platform_build);
	virtual ~c_halo4_cache_cluster();

	BCS_RESULT get_debug_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_debug_reader*& debug_reader);
	BCS_RESULT get_tag_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_tag_reader*& tag_reader);
	BCS_RESULT get_resource_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_resource_reader*& resource_reader);
	BCS_RESULT get_localization_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_localization_reader*& localization_reader);

	BCS_RESULT get_resource_container(s_resource_priority_datas const& resource_priority_datas, c_halo4_resource_container*& resource_container);
	BCS_RESULT add_resource_container(c_halo4_resource_container& resource_container, bool force = false);

	virtual BCS_RESULT get_blofeld_tag_groups(const blofeld::s_tag_group**& tag_groups) const;
	virtual BCS_RESULT get_engine_platform_build(s_engine_platform_build& engine_platform_build) const;
	virtual BCS_RESULT get_cache_readers(c_cache_file_reader* const*& cache_readers, unsigned long& cache_reader_count) const;
	virtual BCS_RESULT get_cache_readers(c_halo4_cache_file_reader* const*& cache_readers, unsigned long& cache_reader_count) const;

protected:
	virtual BCS_RESULT get_debug_reader(c_cache_file_reader& cache_reader, c_debug_reader*& debug_reader);
	virtual BCS_RESULT get_tag_reader(c_cache_file_reader& cache_reader, c_tag_reader*& tag_reader);
	virtual BCS_RESULT get_resource_reader(c_cache_file_reader& cache_reader, c_resource_reader*& resource_reader);
	virtual BCS_RESULT get_localization_reader(c_cache_file_reader& cache_reader, c_localization_reader*& localization_reader);

protected:
	using t_cache_readers = std::vector<c_halo4_cache_file_reader*>;
	using t_debug_readers = std::unordered_map<c_halo4_cache_file_reader*, c_halo4_debug_reader*>;
	using t_tag_readers = std::unordered_map<c_halo4_cache_file_reader*, c_halo4_tag_reader*>;
	using t_resource_readers = std::unordered_map<c_halo4_cache_file_reader*, c_halo4_resource_reader*>;
	using t_localization_readers = std::unordered_map<c_halo4_cache_file_reader*, c_halo4_localization_reader*>;

	t_cache_readers cache_readers;
	t_debug_readers debug_readers;
	t_tag_readers tag_readers;
	t_resource_readers resource_readers;
	t_localization_readers localization_readers;

	s_engine_platform_build engine_platform_build;


	using t_resource_container_by_id_map = std::unordered_map<unsigned long long, c_halo4_resource_container*>;
	using t_resource_container_cache_reader_map = std::unordered_map<c_halo4_cache_file_reader*, std::vector<c_halo4_resource_container*>>;

	t_resource_container_by_id_map resource_containers_by_id;
	t_resource_container_cache_reader_map resource_containers_by_cache_reader;
	std::vector<c_halo4_resource_container*> resource_containers;
	
	BCS_RESULT get_cache_reader_by_relative_path(const char* relative_path, c_halo4_cache_file_reader*& cache_reader);
};
