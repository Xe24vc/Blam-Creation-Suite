#include "mandrilllib-private-pch.h"

c_halo3_tag_group::c_halo3_tag_group(c_halo3_cache_cluster& cache_cluster, const blofeld::s_tag_group& blofeld_tag_group, c_halo3_tag_group* parent) :
	cache_cluster(cache_cluster),
	parent(parent),
	blofeld_tag_group(blofeld_tag_group)
{

}

c_halo3_tag_group::~c_halo3_tag_group()
{

}

BCS_RESULT c_halo3_tag_group::get_blofeld_tag_group(const blofeld::s_tag_group*& out_blofeld_tag_group) const
{
	out_blofeld_tag_group = &blofeld_tag_group;
	return BCS_S_OK;
}

BCS_RESULT c_halo3_tag_group::get_group_tag(tag& out_group_tag) const
{
	out_group_tag = blofeld_tag_group.group_tag;
	return BCS_S_OK;
}

BCS_RESULT c_halo3_tag_group::get_group_name(const char*& out_group_name) const
{
	out_group_name = blofeld_tag_group.name;
	return BCS_S_OK;
}

BCS_RESULT c_halo3_tag_group::get_group_short_name(const char*& out_group_short_name) const
{
	out_group_short_name = blofeld_tag_group.group_tag_short_string;
	return BCS_S_OK;
}