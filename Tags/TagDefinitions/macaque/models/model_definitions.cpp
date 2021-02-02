#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MODEL_STRUCT_DEFINITION_ID { 0xAB569A7E, 0xC76C4EA3, 0x99F00227, 0xD006A3D8 }
	TAG_BLOCK(
		model_block,
		"model_block",
		1,
		"s_model_definition",
		MODEL_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "MODEL", "" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_high_level_model_tag),
		{ _field_tag_reference, "render model", &render_model_reference$2 },
		{ _field_tag_reference, "collision model", &collision_model_reference },
		{ _field_tag_reference, "animation", &global_animation_graph_reference },
		{ _field_tag_reference, "physics_model", &physics_model_reference },
		{ _field_tag_reference, "imposter model", &imposter_model_reference$2 },
		{ _field_long_integer, "runtime render checksum" },
		{ _field_long_integer, "runtime collision checksum" },
		{ _field_explanation, "Optional Static Lightmap", "\n" },
		{ _field_tag_reference, "Lighting Info", &structure_lighting_bsp_reference },
		{ _field_long_enum, "Size Class", &scenario_structure_size_enum },
		{ _field_long_flags, "Lightmap Flags", &model_lightmap_flags_definition },
		{ _field_long_block_index, "Lightmap Variant", &model_variant_block },
		{ _field_explanation, "PVS", "\n" },
		{ _field_real, "PVS bounding box extension factor ", "How much we extend the PVS region around the objects AABB : [good initial value 2.5]" },
		{ _field_real_vector_3d, "PVS block size ", "How big a single PVS block is, in world units : [good initial value (2.0,2.0,2.0)]" },
		{ _field_long_integer, "PVS sampling subdivision per axis ", "How many sample subdivisions we perform per PVS block when generating the data : [good initial value 2]" },
		{ _field_real, "PVS visibility threshold ", "Minimum amount we need to see of an individual part mesh to care about it : [good initial value 0.004]" },
		{ _field_explanation, "level of detail", "\n" },
		{ _field_real, "disappear distance", "world units" },
		{ _field_real, "begin fade distance", "world units" },
		{ _field_real, "animation lod distance", "world units" },
		{ _field_real, "shadow fade distance", "NOTE this is only a maximum distance, shadows may fade closer when you exceed the shadow budget, you should balance the total shadows in a scene", "world units" },
		{ _field_real, "imposter render distance", "world units" },
		{ _field_enum, "imposter quality", &imposter_quality_definition },
		{ _field_enum, "imposter policy", &imposter_policy_definition },
		{ _field_real, "imposter brightness adjustment" },
		{ _field_real, "instance disappear distance", "world units" },
		{ _field_real, "midrange detail disappear distance", "distance at which the midrange detail disappears", "world units" },
		{ _field_real, "close detail disappear distance", "distance at which the close detail disappears", "world units" },
		{ _field_real, "tessellation max draw distance", "world units" },
		{ _field_long_flags, "resource distance override flags", &model_lod_resource_distance_flags_definition },
		{ _field_real, "medium priority distance" },
		{ _field_real, "low priority distance" },
		{ _field_block, "variants", &model_variant_block },
		{ _field_block, "region sort", &region_name_block },
		{ _field_block, "instance groups", &global_model_instance_group_block },
		{ _field_block, "model materials", &model_material_block_new_block },
		{ _field_block, "new damage info", &global_damage_info_block },
		{ _field_struct, "damage info", &model_damage_info_struct },
		{ _field_block, "targets old", &model_target_block_old_block },
		{ _field_block, "model targets", &model_target_block_new_block },
		{ _field_block, "runtime regions", &model_region_block },
		{ _field_block, "runtime nodes", &model_node_block },
		{ _field_long_integer, "runtime node list checksum" },
		{ _field_explanation, "more stuff", "" },
		{ _field_tag_reference, "default dialogue", &dialogue_reference$3 },
		{ _field_tag_reference, "default dialogue female", &dialogue_reference$3 },
		{ _field_long_flags, "flags", &model_flags_definition },
		{ _field_string_id, "default dialogue effect", "The default dialogue tag for this model (overriden by variants)" },
		{ _field_array, "render-only node flags", &g_node_flag_storage_array },
		{ _field_array, "render-only section flags", &g_node_flag_storage_array },
		{ _field_long_flags, "runtime flags", &model_private_flags_definition },
		{ _field_block, "scenario load parameters", &global_scenario_load_parameters_block },
		{ _field_block, "game mode render model override", &model_game_mode_render_model_override_block },
		{ _field_real_fraction, "Sky parallax percent", "If flag checked % between sky pos and camera pos 0=camera" },
		{ _field_real, "shadow depth compare bias", "Default is 0.002" },
		{ _field_real, "shadow slope scale bias", "controls cutoff point for shadows around edges.  Default is 81 degrees", "degrees" },
		{ _field_real, "shadow depth compare bias (dynamic lights)", "Default is 0.0008" },
		{ _field_real, "shadow slope scale bias (dynamic lights)", "controls cutoff point for shadows around edges.  Default is 81 degrees", "degrees" },
		{ _field_explanation, "PRT Shadows (soft self-shadow)", "By default, the shadows on each permutation are computed using the first permutation in\nevery other region as shadow casters.  You can override this behavior below by specifying\nwhich permutation to use as a shadow caster in a given region.\n\n  PRT shadow bounces:\n    the number of light bounces to use when computing the global illumination.\n    (0 bounces gets only direct light).  Increasing the number of bounces\n    increases the calculation time.  1 or 2 bounces should be good enough for\n    almost all models.\n" },
		{ _field_char_enum, "PRT shadow detail", &model_self_shadow_detail_definition },
		{ _field_char_enum, "PRT shadow bounces", &model_self_shadow_bounces_definition },
		FIELD_PAD("NCFGBA", nullptr, 2),
		{ _field_block, "shadow cast override", &model_self_shadow_region_cast_override_block },
		{ _field_block, "shadow receive override", &model_self_shadow_region_receive_override_block },
		{ _field_block, "occlusion spheres", &model_occlusion_sphere_block },
		{ _field_explanation, "Shield impact overrides", "Regular and 1st person shield impact effect overrides\n" },
		{ _field_tag_reference, "shield impact parameter override", &global_shield_parameters_reference },
		{ _field_tag_reference, "1st person shield impact parameter override", &global_shield_parameters_reference },
		{ _field_real, "runtime bounding radius", "world units" },
		{ _field_real_point_3d, "runtime bounding offset" },
		{ _field_terminator }
	};

	TAG_GROUP(
		model_group,
		MODEL_TAG,
		nullptr,
		INVALID_TAG,
		model_block );

	#define MODEL_VARIANT_BLOCK_ID { 0x539CDDB4, 0x7412487A, 0x91B85DAA, 0xC3AAF510 }
	TAG_BLOCK(
		model_variant_block,
		"variant",
		k_maximum_variants_per_model,
		"s_model_variant",
		MODEL_VARIANT_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_array, "runtime variant region indices", &runtime_region_index_array },
		{ _field_block, "regions", &model_variant_region_block },
		{ _field_block, "objects", &model_variant_object_block },
		{ _field_long_block_index, "instance group", &global_model_instance_group_block },
		{ _field_block, "muted nodes", &model_variant_muted_node_block },
		{ _field_array, "muted flag", &g_node_flag_storage_array },
		{ _field_terminator }
	};

	#define MODEL_VARIANT_REGION_BLOCK_ID { 0x070F6AFA, 0x05F64F74, 0xBAFFFFE6, 0x12F8BD5C }
	TAG_BLOCK(
		model_variant_region_block,
		"region",
		MAXIMUM_REGIONS_PER_MODEL,
		"s_model_variant_region",
		MODEL_VARIANT_REGION_BLOCK_ID)
	{
		{ _field_string_id, "region name", "must match region name in render_model" },
		{ _field_char_integer, "runtime region index" },
		{ _field_byte_integer, "runtime flags" },
		{ _field_short_block_index, "parent variant", &model_variant_block },
		{ _field_block, "permutations", &model_variant_permutation_block },
		{ _field_enum, "sort order", &region_sort_enum },
		FIELD_PAD("JO", nullptr, 2),
		{ _field_terminator }
	};

	#define MODEL_VARIANT_PERMUTATION_BLOCK_ID { 0x4ED99004, 0x1D7045CC, 0x98959600, 0x6C3550AD }
	TAG_BLOCK(
		model_variant_permutation_block,
		"permutation",
		MAXIMUM_PERMUTATIONS_PER_MODEL_REGION,
		"s_model_variant_permutation",
		MODEL_VARIANT_PERMUTATION_BLOCK_ID)
	{
		{ _field_string_id, "permutation name" },
		{ _field_char_integer, "runtime permutation index" },
		{ _field_byte_flags, "flags", &model_variant_permutation_flags_definition },
		FIELD_PAD("KSJOSR", nullptr, 2),
		{ _field_real, "probability", "(0,+inf)" },
		{ _field_block, "states", &model_variant_state_block },
		{ _field_array, "runtime state permutation indices", &model_state_permutation_index_array },
		FIELD_PAD("LOOEL", nullptr, 7),
		{ _field_terminator }
	};

	#define MODEL_VARIANT_STATE_BLOCK_ID { 0xDD3D5ACB, 0xC81742A9, 0x911C9F78, 0x4A18CA81 }
	TAG_BLOCK(
		model_variant_state_block,
		"model_variant_state_block",
		MAXIMUM_STATES_PER_MODEL_PERMUTATION,
		"s_model_variant_state",
		MODEL_VARIANT_STATE_BLOCK_ID)
	{
		{ _field_string_id, "permutation name" },
		{ _field_char_integer, "runtime permutation index" },
		{ _field_byte_flags, "property flags", &model_state_property_flags_definition },
		{ _field_enum, "state", &model_state_enum_definition },
		{ _field_real_fraction, "initial probability" },
		{ _field_terminator }
	};

	#define MODEL_VARIANT_OBJECT_BLOCK_ID { 0x86B36FDB, 0xEAD546C3, 0xB0190BC3, 0x34938689 }
	TAG_BLOCK(
		model_variant_object_block,
		"object",
		k_maximum_objects_per_model_variant,
		"s_model_variant_object",
		MODEL_VARIANT_OBJECT_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, _field_id_marker),
		{ _field_string_id, "parent marker" },
		{ _field_string_id, "parent controlling seat label", "the seat in my parent that will control me" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_marker),
		{ _field_string_id, "child marker" },
		{ _field_string_id, "child variant name", "optional" },
		{ _field_tag_reference, "child object", &object_reference$5 },
		{ _field_short_block_index, "damage section", &new_global_damage_section_block },
		{ _field_byte_flags, "flags", &ModelVariantObjectFlagsDefinition },
		FIELD_PAD("MVOBP1", nullptr, 1),
		{ _field_terminator }
	};

	#define GLOBAL_MODEL_INSTANCE_GROUP_BLOCK_ID { 0xE2233121, 0xFA0F464B, 0x93BEE223, 0x29DA60B2 }
	TAG_BLOCK(
		global_model_instance_group_block,
		"instance group",
		k_maximum_instance_groups_per_model,
		"c_model_instance_group",
		GLOBAL_MODEL_INSTANCE_GROUP_BLOCK_ID)
	{
		{ _field_string_id, "name", "name of this instance group" },
		{ _field_long_enum, "choice", &model_instance_group_choice_enum },
		{ _field_block, "member list", &model_instance_group_member_block },
		{ _field_real, "total probability" },
		{ _field_terminator }
	};

	#define MODEL_INSTANCE_GROUP_MEMBER_BLOCK_ID { 0xB9F452BD, 0xE5364484, 0xBCA75D3E, 0x096AF278 }
	TAG_BLOCK(
		model_instance_group_member_block,
		"instance group member",
		k_maximum_members_per_instance_group,
		"c_model_instance_group_member",
		MODEL_INSTANCE_GROUP_MEMBER_BLOCK_ID)
	{
		{ _field_long_block_index, "subgroup", &global_model_instance_group_block },
		{ _field_string_id, "instances", "instance name, a partial name will choose all matching instances, leave blank for NONE" },
		{ _field_real, "probability", "higher numbers make it more likely", "> 0.0" },
		{ _field_long_integer, "instance placement mask 0" },
		{ _field_long_integer, "instance placement mask 1" },
		{ _field_long_integer, "instance placement mask 2" },
		{ _field_long_integer, "instance placement mask 3" },
		{ _field_terminator }
	};

	#define MODEL_VARIANT_MUTED_NODE_BLOCK_ID { 0xFBAAF7D3, 0x5A714A16, 0x9A3638D1, 0xC70FEEF5 }
	TAG_BLOCK(
		model_variant_muted_node_block,
		"muted node",
		k_maximum_muted_nodes_per_model_variant,
		"string_id",
		MODEL_VARIANT_MUTED_NODE_BLOCK_ID)
	{
		{ _field_string_id, "node name", "must match node name in render_model" },
		{ _field_terminator }
	};

	#define REGION_NAME_BLOCK_ID { 0xD0B3901B, 0xC2D24E95, 0x86D47E0D, 0xE9133E84 }
	TAG_BLOCK(
		region_name_block,
		"region_name_block",
		k_kilo,
		"string_id",
		REGION_NAME_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_terminator }
	};

	#define MODEL_MATERIAL_BLOCK_NEW_ID { 0x9D7DA35A, 0x8B7E4FD9, 0x9C66D02E, 0xB415A680 }
	TAG_BLOCK(
		model_material_block_new_block,
		"material",
		MAXIMUM_MATERIALS_PER_MODEL,
		"s_model_material",
		MODEL_MATERIAL_BLOCK_NEW_ID)
	{
		{ _field_string_id, "material name" },
		FIELD_PAD("unused flags", nullptr, 2),
		{ _field_short_block_index, "damage section", &new_global_damage_section_block },
		{ _field_short_integer, "runtime collision material index" },
		{ _field_short_integer, "runtime damager material index" },
		{ _field_string_id, "global material name" },
		{ _field_short_integer, "runtime global material index" },
		FIELD_PAD("SEWETKHRE", nullptr, 2),
		{ _field_terminator }
	};

	#define MODEL_TARGET_BLOCK_OLD_ID { 0x98F4CB8B, 0xA25646F3, 0x9B244873, 0xF1005E11 }
	TAG_BLOCK(
		model_target_block_old_block,
		"model_target_block_old",
		MAXIMUM_MODEL_TARGETS_PER_MODEL,
		"s_model_target_old",
		MODEL_TARGET_BLOCK_OLD_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, _field_id_marker),
		{ _field_string_id, "marker name", "multiple markers become multiple spheres of the same radius" },
		{ _field_real, "size", "sphere radius" },
		{ _field_angle, "cone angle", "the target is only visible when viewed within this angle of the marker\'s x axis" },
		{ _field_custom_short_block_index, "damage section", "the target is associated with this damage section" },
		{ _field_short_block_index, "variant", &model_variant_block },
		{ _field_real_fraction, "targeting relevance", "higher relevances turn into stronger magnetisms" },
		{ _field_real, "aoe exclusion radius", "ignored if zero" },
		{ _field_struct, "lock-on data", &model_target_lock_on_data_struct },
		{ _field_terminator }
	};

	#define MODEL_TARGET_BLOCK_NEW_ID { 0x9ECA6B32, 0x09EF4F1E, 0xAC641ADB, 0x98E0337B }
	TAG_BLOCK(
		model_target_block_new_block,
		"model_target_block_new",
		MAXIMUM_MODEL_TARGETS_PER_MODEL,
		"s_model_target",
		MODEL_TARGET_BLOCK_NEW_ID)
	{
		{ _field_byte_flags, "flags", &model_target_flags_definition },
		FIELD_PAD("MTBNP1", nullptr, 3),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_marker),
		{ _field_string_id, "marker name", "multiple markers become multiple spheres of the same radius" },
		{ _field_real, "size", "sphere radius" },
		{ _field_angle, "cone angle", "the target is only visible when viewed within this angle of the marker\'s x axis" },
		{ _field_short_block_index, "damage section", &new_global_damage_section_block },
		{ _field_short_block_index, "variant", &model_variant_block },
		{ _field_real_fraction, "targeting relevance", "higher relevances turn into stronger magnetisms" },
		{ _field_real, "aoe exclusion radius", "ignored if zero" },
		{ _field_struct, "lock-on data", &model_target_lock_on_data_struct },
		{ _field_terminator }
	};

	#define MODEL_REGION_BLOCK_ID { 0x4E1EFAA1, 0x9CA248F7, 0x9223106F, 0xC7A5C1A4 }
	TAG_BLOCK(
		model_region_block,
		"model_region_block",
		MAXIMUM_REGIONS_PER_MODEL,
		"s_model_region",
		MODEL_REGION_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_char_integer, "collision region index" },
		{ _field_char_integer, "physics region index" },
		FIELD_PAD("QDSJS", nullptr, 2),
		{ _field_block, "permutations", &model_permutation_block },
		{ _field_terminator }
	};

	#define MODEL_PERMUTATION_BLOCK_ID { 0x72671B5F, 0x63CE4207, 0xBE9A29D5, 0x3EB1033F }
	TAG_BLOCK(
		model_permutation_block,
		"model_permutation_block",
		MAXIMUM_PERMUTATIONS_PER_MODEL_REGION,
		"s_model_permutation",
		MODEL_PERMUTATION_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_byte_flags, "flags", &model_permutation_flags_definition },
		{ _field_char_integer, "collision permutation index" },
		{ _field_char_integer, "physics permutation index" },
		FIELD_PAD("AVZQS", nullptr, 1),
		{ _field_terminator }
	};

	#define MODEL_NODE_BLOCK_ID { 0xE5E9FB01, 0xF8384408, 0xAFEC9EFF, 0x28E7E6F4 }
	TAG_BLOCK(
		model_node_block,
		"model_node_block",
		MAXIMUM_NODES_PER_MODEL,
		"s_model_node",
		MODEL_NODE_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_short_block_index, "parent node", &model_node_block },
		{ _field_short_block_index, "first child node", &model_node_block },
		{ _field_short_block_index, "next sibling node", &model_node_block },
		FIELD_PAD("GHTI", nullptr, 2),
		{ _field_real_point_3d, "default translation" },
		{ _field_real_quaternion, "default rotation" },
		{ _field_real, "default inverse scale" },
		{ _field_real_vector_3d, "default inverse forward" },
		{ _field_real_vector_3d, "default inverse left" },
		{ _field_real_vector_3d, "default inverse up" },
		{ _field_real_point_3d, "default inverse position" },
		{ _field_terminator }
	};

	#define MODEL_GAME_MODE_RENDER_MODEL_OVERRIDE_ID { 0x6DD2DC3C, 0x333C4458, 0xA2BABBF8, 0x84C20B15 }
	TAG_BLOCK(
		model_game_mode_render_model_override_block,
		"game mode render model override",
		k_maximum_model_game_mode_types,
		"s_model_game_mode_render_model_override",
		MODEL_GAME_MODE_RENDER_MODEL_OVERRIDE_ID)
	{
		{ _field_enum, "game mode", &model_game_mode_types },
		FIELD_PAD("BL", nullptr, 2),
		{ _field_tag_reference, "render model override", &render_model_reference$3 },
		{ _field_terminator }
	};

	#define MODEL_SELF_SHADOW_REGION_CAST_OVERRIDE_BLOCK_ID { 0x9AAFE87A, 0xEB8C4EC7, 0x89BAEF7B, 0x7ADE02DB }
	TAG_BLOCK(
		model_self_shadow_region_cast_override_block,
		"model_self_shadow_region_cast_override_block",
		MAXIMUM_REGIONS_PER_MODEL,
		"s_prt_region_shadow_cast_override",
		MODEL_SELF_SHADOW_REGION_CAST_OVERRIDE_BLOCK_ID)
	{
		{ _field_string_id, "region" },
		{ _field_string_id, "shadow cast permutation", "leave blank for none" },
		{ _field_terminator }
	};

	#define MODEL_SELF_SHADOW_REGION_RECEIVE_OVERRIDE_BLOCK_ID { 0x7EB85F6C, 0x6B57414C, 0xAF117275, 0x5EA33656 }
	TAG_BLOCK(
		model_self_shadow_region_receive_override_block,
		"model_self_shadow_region_receive_override_block",
		MAXIMUM_REGIONS_PER_MODEL,
		"s_prt_region_shadow_receive_override",
		MODEL_SELF_SHADOW_REGION_RECEIVE_OVERRIDE_BLOCK_ID)
	{
		{ _field_string_id, "region" },
		{ _field_long_enum, "shadow type", &model_prt_shadow_receive_mode_definition },
		{ _field_terminator }
	};

	#define MODEL_OCCLUSION_SPHERE_BLOCK_ID { 0x6301C370, 0x3F4846FD, 0x8AF5CD6F, 0x79C5363C }
	TAG_BLOCK(
		model_occlusion_sphere_block,
		"model_occlusion_sphere_block",
		MAXIMUM_REGIONS_PER_MODEL,
		"s_model_occlusion_sphere",
		MODEL_OCCLUSION_SPHERE_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, _field_id_marker),
		{ _field_string_id, "marker 1 name" },
		{ _field_long_integer, "marker 1 index" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_marker),
		{ _field_string_id, "marker 2 name" },
		{ _field_long_integer, "marker 2 index" },
		{ _field_real, "radius" },
		{ _field_terminator }
	};

	#define RUNTIME_REGION_INDEX_ARRAY_ID { 0x698D671C, 0x87E64985, 0x8D63EF05, 0xF3EAE84E }
	TAG_ARRAY(
		runtime_region_index_array,
		"runtime_region_index_array",
		MAXIMUM_REGIONS_PER_MODEL,
		"char",
		RUNTIME_REGION_INDEX_ARRAY_ID)
	{
		{ _field_char_integer, "runtime region index" },
		{ _field_terminator }
	};

	#define MODEL_STATE_PERMUTATION_INDEX_ARRAY_ID { 0x42CDCB9B, 0x148440EA, 0xB21C6D08, 0xB3C86C53 }
	TAG_ARRAY(
		model_state_permutation_index_array,
		"model_state_permutation_index_array",
		k_number_of_model_states,
		"char",
		MODEL_STATE_PERMUTATION_INDEX_ARRAY_ID)
	{
		{ _field_char_integer, "runtime permutation index" },
		{ _field_terminator }
	};

	#define MODEL_TARGET_LOCK_ON_DATA_STRUCT_ID { 0x3BEBBCB0, 0xF83B4943, 0x9C36F114, 0x2C166B4D }
	TAG_STRUCT(
		model_target_lock_on_data_struct,
		"model_target_lock_on_data_struct",
		"s_model_target_lock_on_data",
		MODEL_TARGET_LOCK_ON_DATA_STRUCT_ID)
	{
		{ _field_explanation, "lock-on fields", "" },
		{ _field_byte_flags, "flags", &model_target_lock_on_flags_definition },
		FIELD_PAD("SVLKJERAF", nullptr, 3),
		{ _field_real, "lock on distance" },
		{ _field_string_id, "tracking type", "a weapon can track/lock on this target if this string is in the weapon\'s tracking block" },
		{ _field_terminator }
	};

	STRINGS(model_flags_definition)
	{
		"active camo always on",
		"active camo never",
		"inconsequential target#used in magnetism and campaign saving",
		"model use airprobe lighting first{model use airprobe lighting}",
		"locked precomputed probes#air or scenery probe",
		"If sky attaches to camera#parallax % between sky pos and camera pos below",
		"model is big battle object",
		"model never uses compressed vertex position",
		"model is invisible, even attachments",
		"model can have shield impact effect!*",
		"model is good z occluder",
		"no child objects in lightmap shadow",
		"should include model in floating shadow"
	};
	STRING_LIST(model_flags_definition, model_flags_definition_strings, _countof(model_flags_definition_strings));

	STRINGS(model_private_flags_definition)
	{
		"contains run-time nodes"
	};
	STRING_LIST(model_private_flags_definition, model_private_flags_definition_strings, _countof(model_private_flags_definition_strings));

	STRINGS(model_lightmap_flags_definition)
	{
		"pvs enabled",
		"per vertex all",
		"generate forge atlas"
	};
	STRING_LIST(model_lightmap_flags_definition, model_lightmap_flags_definition_strings, _countof(model_lightmap_flags_definition_strings));

	STRINGS(model_lod_resource_distance_flags_definition)
	{
		"override enabled"
	};
	STRING_LIST(model_lod_resource_distance_flags_definition, model_lod_resource_distance_flags_definition_strings, _countof(model_lod_resource_distance_flags_definition_strings));

	STRINGS(imposter_quality_definition)
	{
		"default",
		"high",
		"super"
	};
	STRING_LIST(imposter_quality_definition, imposter_quality_definition_strings, _countof(imposter_quality_definition_strings));

	STRINGS(imposter_policy_definition)
	{
		"default",
		"never",
		"always"
	};
	STRING_LIST(imposter_policy_definition, imposter_policy_definition_strings, _countof(imposter_policy_definition_strings));

	STRINGS(model_game_mode_types)
	{
		"campaign",
		"multiplayer",
		"firefight",
		"mainmenu"
	};
	STRING_LIST(model_game_mode_types, model_game_mode_types_strings, _countof(model_game_mode_types_strings));

	STRINGS(model_variant_permutation_flags_definition)
	{
		"copy states to all permutations"
	};
	STRING_LIST(model_variant_permutation_flags_definition, model_variant_permutation_flags_definition_strings, _countof(model_variant_permutation_flags_definition_strings));

	STRINGS(model_state_property_flags_definition)
	{
		"blurred",
		"hella blurred",
		"unshielded{shielded}",
		"battery depleted"
	};
	STRING_LIST(model_state_property_flags_definition, model_state_property_flags_definition_strings, _countof(model_state_property_flags_definition_strings));

	STRINGS(region_sort_enum)
	{
		"no sorting",
		"-5 (closest)",
		"-4",
		"-3",
		"-2",
		"-1",
		"0 (same as model)",
		"1",
		"2",
		"3",
		"4",
		"5 (farthest)"
	};
	STRING_LIST(region_sort_enum, region_sort_enum_strings, _countof(region_sort_enum_strings));

	STRINGS(ModelVariantObjectFlagsDefinition)
	{
		"enable physics"
	};
	STRING_LIST(ModelVariantObjectFlagsDefinition, ModelVariantObjectFlagsDefinition_strings, _countof(ModelVariantObjectFlagsDefinition_strings));

	STRINGS(model_instance_group_choice_enum)
	{
		"choose one member",
		"choose all members"
	};
	STRING_LIST(model_instance_group_choice_enum, model_instance_group_choice_enum_strings, _countof(model_instance_group_choice_enum_strings));

	STRINGS(model_target_lock_on_flags_definition)
	{
		"headshot",
		"vulnerable",
		"ignored on local physics",
		"use for network lead vector only"
	};
	STRING_LIST(model_target_lock_on_flags_definition, model_target_lock_on_flags_definition_strings, _countof(model_target_lock_on_flags_definition_strings));

	STRINGS(model_target_flags_definition)
	{
		"aoe top level",
		"aoe test obstruction",
		"shows tracking reticle#use this model targets center for displaying the targetting reticle"
	};
	STRING_LIST(model_target_flags_definition, model_target_flags_definition_strings, _countof(model_target_flags_definition_strings));

	STRINGS(model_permutation_flags_definition)
	{
		"cannot be chosen randomly"
	};
	STRING_LIST(model_permutation_flags_definition, model_permutation_flags_definition_strings, _countof(model_permutation_flags_definition_strings));

	STRINGS(model_self_shadow_detail_definition)
	{
		"Ambient Occlusion (2 bytes per vertex){0}",
		"Linear (8 bytes per vertex){1}",
		"Quadratic (18 bytes per vertex){2}"
	};
	STRING_LIST(model_self_shadow_detail_definition, model_self_shadow_detail_definition_strings, _countof(model_self_shadow_detail_definition_strings));

	STRINGS(model_self_shadow_bounces_definition)
	{
		"0 bounces (very fast, direct light only)",
		"1 bounce  (slower, pretty good)",
		"2 bounces (molasses, very good)",
		"3 bounces (sloth in molasses, overkill really)"
	};
	STRING_LIST(model_self_shadow_bounces_definition, model_self_shadow_bounces_definition_strings, _countof(model_self_shadow_bounces_definition_strings));

	STRINGS(model_prt_shadow_receive_mode_definition)
	{
		"PRT shadows from all regions (default permutations)",
		"PRT self-shadow only (no shadows from other regions)",
		"No PRT shadows at all (probably not useful)"
	};
	STRING_LIST(model_prt_shadow_receive_mode_definition, model_prt_shadow_receive_mode_definition_strings, _countof(model_prt_shadow_receive_mode_definition_strings));

} // namespace macaque

} // namespace blofeld
