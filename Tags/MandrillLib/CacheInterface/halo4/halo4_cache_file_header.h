#pragma once

/* ---------- types */

namespace halo4
{
	namespace pc
	{
//#pragma pack(push, 4)
//		struct s_cache_file_header : ::s_cache_file_header
//		{
//			intptr64_t tags_header_address;
//			long tag_buffer_offset;
//			long total_tags_size;
//			c_static_string<256> source_file;
//			c_static_string<32> build;
//			c_enum_no_init<gen3::e_scenario_type, short> scenario_type;
//			c_enum_no_init<gen3::e_scenario_load_type, short> scenario_load_type;
//			bool unknown140;
//			bool tracked_build;
//			bool unknown142; // something involved with packages
//			c_flags_no_init<gen3::e_cache_file_header_bit, unsigned char> header_flags;
//			long unknown144;
//			long unknown148;
//			long unknown14C;
//			long unknown150;
//			long unknown154;
//			long string_id_index_buffer_count;
//			long string_id_string_storage_size;
//			long string_id_index_buffer_offset;
//			long string_id_string_storage_offset;
//			c_flags_no_init<gen3::e_cache_file_shared_file_type, unsigned char> shared_file_type_flags; // see cached_map_file_dependencies_loaded for more information
//			gen3::s_file_last_modification_date timestamp; // see cached_map_file_dependencies_loaded for more information
//			gen3::s_file_last_modification_date scenario_type_timestamps[3]; // see cached_map_file_dependencies_loaded for more information
//			c_static_string<32> name;
//			long unknown1AC;
//			c_static_string<256> scenario_path;
//			long minor_version;
//			long file_count;
//			long file_table_offset;
//			long file_table_length;
//			long file_table_indices_offset;
//
//			unsigned long tag_remap_count;
//			unsigned long tag_remap_address;
//			unsigned long dlc_tag_remap_count;
//			unsigned long dlc_tag_remap_address;
//
//			long unknown2D4;
//			c_static_string<32> unknown2D8;
//			intptr64_t expected_base_address;
//			unsigned long xdk_version;
//			c_basic_buffer64<void> tag_post_link_buffer;
//			c_basic_buffer64<void> tag_language_dependent_read_only_buffer;
//			c_basic_buffer64<void> tag_language_dependent_read_write_buffer;
//			c_basic_buffer64<void> tag_language_neutral_read_write_buffer;
//			c_basic_buffer64<void> tag_language_neutral_write_combined_buffer;
//			c_basic_buffer64<void> tag_language_neutral_read_only_buffer;
//			long unknown330;
//			long unknown334;
//			long unknown478;
//			long unknown338;
//			gen3::s_network_http_request_hash hash;
//			gen3::s_rsa_signature rsa;
//			s_static_array<long, gen3::k_num_cache_file_section> offset_masks;
//			s_static_array<gen3::s_cache_file_section_file_bounds, gen3::k_num_cache_file_section> section_file_bounds;
//			//unsigned int unknown4AC;
//
//			//unsigned __int8 gap4B0[100836];
//
//			//unsigned __int8 unknown18E94;
//			//unsigned __int8 unknown18E95;
//			//unsigned __int8 unknown18E96;
//			//unsigned __int8 unknown18E97;
//
//			//s_static_array<gen3::s_cache_file_insertion_point_resource_usage, 12> insertion_point_resource_usage;
//
//			//char gap1D728[16];
//
//			//unsigned long late_binding_tag_reference_fixup_info_count;
//			//unsigned long late_binding_tag_reference_fixup_info_address;
//
//			//char gap1D740[2236];
//			
//			tag footer_signature;
//
//			byteswap_inplace();
//		};
//#pragma pack(pop)
//
//
//		
//		static constexpr long k_cache_file_header_size = sizeof(s_cache_file_header);
//		static_assert(k_cache_file_header_size == 0x1E000);
	}
	
	namespace xbox360
	{
#pragma pack(push, 4)
		struct s_cache_file_header : ::s_cache_file_header
		{
			uintptr32_t tags_header_address;
			long tag_buffer_offset;
			long total_tags_size;
			c_static_string<256> source_file;
			c_static_string<32> build;
			c_enum_no_init<gen3::e_scenario_type, short> scenario_type;
			c_enum_no_init<gen3::e_scenario_load_type, short> scenario_load_type;
			bool unknown140;
			bool tracked_build;
			bool unknown142; // something involved with packages
			c_flags_no_init<gen3::e_cache_file_header_bit, unsigned char> header_flags;
			long unknown144;
			long unknown148;
			long unknown14C;
			long unknown150;
			long unknown154;
			long string_id_index_buffer_count;
			long string_id_string_storage_size;
			long string_id_index_buffer_offset;
			long string_id_string_storage_offset;
			c_flags_no_init<gen3::e_cache_file_shared_file_type, unsigned char> shared_file_type_flags; // see cached_map_file_dependencies_loaded for more information
			gen3::s_file_last_modification_date timestamp; // see cached_map_file_dependencies_loaded for more information
			gen3::s_file_last_modification_date scenario_type_timestamps[3]; // see cached_map_file_dependencies_loaded for more information
			c_static_string<32> name;
			long unknown1AC;
			c_static_string<256> relative_path;
			long minor_version;
			long file_count;
			long file_table_offset;
			long file_table_length;
			long file_table_indices_offset;

			unsigned long tag_remap_count;
			unsigned long tag_remap_address;
			unsigned long dlc_tag_remap_count;
			unsigned long dlc_tag_remap_address;

			long unknown2D4;
			c_static_string<32> unknown2D8;
			uintptr32_t expected_base_address;
			unsigned long xdk_version;
			c_basic_buffer32<void> tag_post_link_buffer;
			c_basic_buffer32<void> tag_language_dependent_read_only_buffer;
			c_basic_buffer32<void> tag_language_dependent_read_write_buffer;
			c_basic_buffer32<void> tag_language_neutral_read_write_buffer;
			c_basic_buffer32<void> tag_language_neutral_write_combined_buffer;
			c_basic_buffer32<void> tag_language_neutral_read_only_buffer;
			long unknown330;
			long unknown334;
			long unknown338;
			long unknown33C;
			gen3::s_network_http_request_hash hash;
			gen3::s_rsa_signature rsa;
			s_static_array<long, gen3::k_num_cache_file_section> offset_masks;
			s_static_array<gen3::s_cache_file_section_file_bounds, gen3::k_num_cache_file_section> section_file_bounds;
			unsigned int unknown4AC;
			unsigned int unknown4B0;
			unsigned int unknown4B4;
			unsigned int unknown4B8;

			unsigned __int8 gap4BC[100824];

			unsigned __int8 unknown18E94;
			unsigned __int8 unknown18E95;
			unsigned __int8 unknown18E96;
			unsigned __int8 unknown18E97;

			s_static_array<gen3::s_cache_file_insertion_point_resource_usage, 12> insertion_point_resource_usage;

			char gap1D728[16];

			unsigned long late_binding_tag_reference_fixup_info_count;
			unsigned long late_binding_tag_reference_fixup_info_address;
			unsigned long cache_file_fixups_count;
			unsigned long cache_file_fixups_address;

			char gap1D748[2228];
			tag footer_signature;
		};
#pragma pack(pop)

		static_assert(offsetof(s_cache_file_header, s_cache_file_header::header_signature												) == 0x00000000);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::file_version                                             		) == 0x00000004);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::file_length                                              		) == 0x00000008);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::file_compressed_length                                   		) == 0x0000000C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::tags_header_address                                      		) == 0x00000010);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::tag_buffer_offset                                        		) == 0x00000014);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::total_tags_size                                          		) == 0x00000018);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::source_file                                              		) == 0x0000001C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::build                                                    		) == 0x0000011C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::scenario_type                                            		) == 0x0000013C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::scenario_load_type                                       		) == 0x0000013E);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown140                                               		) == 0x00000140);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::tracked_build                                            		) == 0x00000141);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown142                                               		) == 0x00000142);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::header_flags                                             		) == 0x00000143);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown144                                               		) == 0x00000144);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown148                                               		) == 0x00000148);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown14C                                               		) == 0x0000014C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown150                                               		) == 0x00000150);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown154                                               		) == 0x00000154);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::string_id_index_buffer_count                             		) == 0x00000158);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::string_id_string_storage_size									) == 0x0000015C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::string_id_index_buffer_offset                            		) == 0x00000160);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::string_id_string_storage_offset								) == 0x00000164);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::shared_file_type_flags                                   		) == 0x00000168);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::timestamp                                                		) == 0x0000016C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::scenario_type_timestamps                                 		) == 0x00000174);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::name                                                     		) == 0x0000018C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown1AC                                               		) == 0x000001AC);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::relative_path                                            		) == 0x000001B0);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::minor_version                                            		) == 0x000002B0);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::file_count                                               		) == 0x000002B4);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::file_table_offset                                        		) == 0x000002B8);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::file_table_length                                        		) == 0x000002BC);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::file_table_indices_offset                                		) == 0x000002C0);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::tag_remap_count                                          		) == 0x000002C4);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::tag_remap_address                                        		) == 0x000002C8);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::dlc_tag_remap_count                                      		) == 0x000002CC);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::dlc_tag_remap_address                                    		) == 0x000002D0);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown2D4                                               		) == 0x000002D4);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown2D8                                               		) == 0x000002D8);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::expected_base_address                                    		) == 0x000002F8);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::xdk_version                                              		) == 0x000002FC);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::tag_post_link_buffer                                     		) == 0x00000300);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::tag_language_dependent_read_only_buffer                  		) == 0x00000308);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::tag_language_dependent_read_write_buffer                 		) == 0x00000310);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::tag_language_neutral_read_write_buffer                   		) == 0x00000318);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::tag_language_neutral_write_combined_buffer               		) == 0x00000320);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::tag_language_neutral_read_only_buffer                    		) == 0x00000328);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown330                                               		) == 0x00000330);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown334                                               		) == 0x00000334);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown338                                               		) == 0x00000338);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown33C                                               		) == 0x0000033C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::hash                                                     		) == 0x00000340);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::rsa                                                      		) == 0x0000037C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::offset_masks                                             		) == 0x0000047C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::section_file_bounds                                      		) == 0x0000048C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown4AC                                               		) == 0x000004AC);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown4B0                                               		) == 0x000004B0);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown4B4                                               		) == 0x000004B4);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown4B8                                               		) == 0x000004B8);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::gap4BC                                                   		) == 0x000004BC);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown18E94                                             		) == 0x00018E94);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown18E95                                             		) == 0x00018E95);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown18E96                                             		) == 0x00018E96);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::unknown18E97                                             		) == 0x00018E97);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::insertion_point_resource_usage                           		) == 0x00018E98);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::gap1D728                                                 		) == 0x0001D728);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::late_binding_tag_reference_fixup_info_count              		) == 0x0001D738);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::late_binding_tag_reference_fixup_info_address            		) == 0x0001D73C);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::cache_file_fixups_count                                  		) == 0x0001D740);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::cache_file_fixups_address                                		) == 0x0001D744);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::gap1D748                                                 		) == 0x0001D748);
		static_assert(offsetof(s_cache_file_header, s_cache_file_header::footer_signature                                         		) == 0x0001DFFC);
		
		static constexpr long k_cache_file_header_size2 = offsetof(s_cache_file_header, s_cache_file_header::footer_signature) + 4;
		static constexpr long k_cache_file_header_size = sizeof(s_cache_file_header);
		//static_assert(k_cache_file_header_size == 0x1E000);

		struct s_cache_file_tag_group
		{
			tag group_tags[3];
			unsigned long name;
		};
		static_assert(sizeof(s_cache_file_tag_group) == 0x10);

		struct s_cache_file_tag_instance
		{
			unsigned short group_index;
			unsigned short identifier;
			unsigned long address;
		};
		static_assert(sizeof(s_cache_file_tag_instance) == 0x8);

		struct s_cache_file_tag_global_instance
		{
			unsigned long group_tag;
			long datum_index;
		};
		static_assert(sizeof(s_cache_file_tag_global_instance) == 0x8);

		struct s_cache_file_tag_interop
		{
			dword page_address;
			long type_index;
		};
		static_assert(sizeof(s_cache_file_tag_interop) == 0x8);

		struct s_section
		{
			unsigned long count = 0;
			intptr32_t address = 0;
		};
		static_assert(sizeof(s_section) == 0x8);

		struct s_cache_file_tags_header
		{
			s_section tag_groups; // s_cache_file_tag_group
			s_section tag_instances; // s_cache_file_tag_instance
			s_section global_tag_instances; // s_cache_file_tag_global_instance
			s_section tag_interop_table; // s_cache_file_tag_interop
			long unknown20;
			dword checksum;
			unsigned long tags_signature;
		};
		static constexpr size_t k_cache_file_tags_header = sizeof(s_cache_file_tags_header);
		static_assert(k_cache_file_tags_header == 0x2C);

		bool cache_file_header_verify(s_cache_file_header& header);
	}

	
}
