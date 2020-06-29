#pragma once

namespace blofeld
{

	constexpr unsigned long LIGHTMAP_MODEL_GLOBALS_TAG = 'LMMg';

	extern s_tag_group lightmap_model_globals_group;
	constexpr unsigned long LIGHTMAPPER_GLOBALS_TAG = 'LMgS';

	extern s_tag_group lightmapper_globals_group;

	extern s_tag_struct_definition lightmap_model_reference_block_block_struct;
	extern s_tag_block_definition lightmap_model_reference_block_block;
	extern s_tag_block_definition lightmap_model_globals_block_block;
	extern s_tag_block_definition lightmapper_globals_block_block;

	extern s_tag_struct_definition lightmap_model_globals_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition lightmapper_globals_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition global_lightmap_global_settings_struct_struct_definition;
	extern s_tag_struct_definition global_lightmap_local_settings_struct_struct_definition;
	extern s_tag_struct_definition global_lightmap_ao_settings_struct_struct_definition;
	extern s_tag_struct_definition global_lightmap_global_illumination_falloff_settings_struct_struct_definition;
	extern s_tag_struct_definition global_lightmap_local_override_settings_struct_struct_definition;

	extern c_versioned_string_list lightmap_mode_enum_strings;
	extern s_string_list_definition lightmap_mode_enum;
	extern c_versioned_string_list lightmap_hemicube_resolution_enum_strings;
	extern s_string_list_definition lightmap_hemicube_resolution_enum;
	extern c_versioned_string_list lightmap_ao_quality_enum_strings;
	extern s_string_list_definition lightmap_ao_quality_enum;
	extern c_versioned_string_list lightmap_dxt_quality_enum_strings;
	extern s_string_list_definition lightmap_dxt_quality_enum;
	extern c_versioned_string_list lightmap_indirect_quality_enum_strings;
	extern s_string_list_definition lightmap_indirect_quality_enum;
	extern c_versioned_string_list lightmap_direct_shadow_map_resolution_enum_strings;
	extern s_string_list_definition lightmap_direct_shadow_map_resolution_enum;
	extern c_versioned_string_list lightmap_supersampling_factor_enum_strings;
	extern s_string_list_definition lightmap_supersampling_factor_enum;
	extern c_versioned_string_list lightmap_local_flags_strings;
	extern s_string_list_definition lightmap_local_flags;
	extern c_versioned_string_list lightmap_global_flags_strings;
	extern s_string_list_definition lightmap_global_flags;

} // namespace blofeld

