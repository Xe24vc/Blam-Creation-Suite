#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(gen3::s_cache_file_section_file_bounds& value)
{
	byteswap_inplace(value.offset);
	byteswap_inplace(value.size);
}

template<> void byteswap_inplace(gen3::s_network_http_request_hash& value)
{

}

template<> void byteswap_inplace(gen3::s_rsa_signature& value)
{

}

template<> void byteswap_inplace(gen3::s_file_last_modification_date& value)
{
	byteswap_inplace(value.unknown0);
	byteswap_inplace(value.unknown4);
}

template<> void byteswap_inplace(gen3::s_cache_file_insertion_point_resource_usage& value)
{
	// #TODO
}
