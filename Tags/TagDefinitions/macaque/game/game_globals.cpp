#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		globals_group,
		GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		globals_block );

	TAG_GROUP(
		patch_globals_group,
		PATCH_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		patch_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		globals_block,
		"globals_block",
		1,
		globals_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		patch_globals_block,
		"patch_globals_block",
		1,
		patch_globals_struct_definition);

	#define HAVOK_CLEANUP_RESOURCES_BLOCK_ID { 0x1158B5B8, 0xFBFC4D5A, 0xB4862259, 0xCB91EB7B }
	TAG_BLOCK(
		havok_cleanup_resources_block,
		"havok_cleanup_resources_block",
		1,
		"s_game_globals_havok_cleanup_resources",
		HAVOK_CLEANUP_RESOURCES_BLOCK_ID)
	{
		{ _field_tag_reference, "object cleanup effect", &global_effect_reference },
		{ _field_terminator }
	};

	#define SOUND_BLOCK_ID { 0xBAB7A89B, 0xDFC743D6, 0xB8895623, 0xEBA18D33 }
	TAG_BLOCK(
		sound_block$2_block,
		"sound_block",
		NUMBER_OF_GLOBAL_SOUNDS,
		"s_tag_reference",
		SOUND_BLOCK_ID)
	{
		{ _field_tag_reference, "sound (OBSOLETE)", &sound_block_sound_OBSOLETE_reference },
		{ _field_terminator }
	};

	#define SOFT_CEILING_GLOBALS_BLOCK_ID { 0x64E57956, 0x36734BA7, 0x83B6CF77, 0xDA4FEAED }
	TAG_BLOCK(
		soft_ceiling_globals_block,
		"soft_ceiling_globals_block",
		1,
		"s_game_globals_soft_ceiling",
		SOFT_CEILING_GLOBALS_BLOCK_ID)
	{
		{ _field_real, "biped spring constant" },
		{ _field_real, "biped normal damping" },
		{ _field_real, "biped tangent damping" },
		{ _field_real, "biped min tangent damp velocity" },
		{ _field_real, "vehicle spring constant" },
		{ _field_real, "vehicle normal damping" },
		{ _field_real, "vehicle tangent damping" },
		{ _field_terminator }
	};

	#define CHEAT_WEAPONS_BLOCK_ID { 0xD13CBBE7, 0x9DEC4ED6, 0x983BA69C, 0x9D39AE04 }
	TAG_BLOCK(
		cheat_weapons_block,
		"cheat_weapons_block",
		20,
		"s_game_globals_tag_reference",
		CHEAT_WEAPONS_BLOCK_ID)
	{
		{ _field_tag_reference, "weapon", &global_item_reference },
		{ _field_terminator }
	};

	#define CHEAT_POWERUPS_BLOCK_ID { 0x60B57D08, 0xF45F431C, 0xBCFF4793, 0x3C28C018 }
	TAG_BLOCK(
		cheat_powerups_block,
		"cheat_powerups_block",
		20,
		"s_game_globals_tag_reference",
		CHEAT_POWERUPS_BLOCK_ID)
	{
		{ _field_tag_reference, "powerup", &global_equipment_reference },
		{ _field_terminator }
	};

	#define MULTIPLAYER_COLOR_BLOCK_ID { 0x0A6C9756, 0xF0E24866, 0xA708F3E9, 0xC9C41962 }
	TAG_BLOCK(
		multiplayer_color_block,
		"multiplayer_color_block",
		k_player_color_index_count,
		"real_rgb_color",
		MULTIPLAYER_COLOR_BLOCK_ID)
	{
		{ _field_real_rgb_color, "color" },
		{ _field_terminator }
	};

	#define VISOR_COLOR_BLOCK_ID { 0x91C73AC2, 0x84F247BD, 0x933B0BAD, 0x26DB133B }
	TAG_BLOCK(
		visor_color_block,
		"visor_color_block",
		32,
		"s_multiplayer_visor_color",
		VISOR_COLOR_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_real_rgb_color, "tertiary color" },
		{ _field_real_rgb_color, "quaternary color" },
		{ _field_terminator }
	};

	#define GLOBALS_STRUCT_DEFINITION_ID { 0x08DE77CB, 0xA2CF4145, 0xBB807A30, 0xB2A866B3 }
	TAG_STRUCT(
		globals_struct_definition,
		"globals_struct_definition",
		"s_game_globals",
		GLOBALS_STRUCT_DEFINITION_ID)
	{
		FIELD_PAD("YJLTWDSL", nullptr, 172),
		{ _field_long_enum, "language", &language_enum },
		{ _field_block, "havok cleanup resources", &havok_cleanup_resources_block },
		{ _field_block, "sound globals", &sound_globals_block },
		{ _field_explanation, "AI globals", "I have moved the ai globals out of this tag, and into its own tag which is referenced here." },
		{ _field_block, "DEPRECATED", &ai_globals_data_block },
		{ _field_tag_reference, "ai globals ref", &ai_globals_reference },
		{ _field_block, "damage table", &game_globals_damage_block },
		{ _field_block, "sounds", &sound_block$2_block },
		{ _field_block, "camera", &camera_block },
		{ _field_block, "controller input", &controller_input_block },
		{ _field_block, "player control", &player_control_block },
		{ _field_block, "default player traits", &game_engine_player_traits_block },
		{ _field_block, "difficulty", &difficulty_block },
		{ _field_block, "co-op difficulty", &coop_difficulty_block },
		{ _field_block, "soft ceilings", &soft_ceiling_globals_block },
		{ _field_block, "interface tags", &interface_tag_references_block },
		{ _field_block, "weapon list", &cheat_weapons_block },
		{ _field_block, "@cheat powerups", &cheat_powerups_block },
		{ _field_block, "@player information", &player_information_block },
		{ _field_block, "@player representation", &player_representation_block },
		{ _field_block, "damage", &damage_globals_block },
		{ _field_block, "shield boost", &shield_boost_block },
		{ _field_block, "materials", &materials_block$3_block },
		{ _field_block, "profile colors", &multiplayer_color_block },
		{ _field_block, "emblem colors", &multiplayer_color_block },
		{ _field_block, "visor colors", &visor_color_block },
		FIELD_CUSTOM("Elite specular colors", nullptr, _field_id_function_group_begin),
		{ _field_struct, "elite specular color", &elite_specular_color_struct },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		{ _field_tag_reference, "forge globals", &forge_globals_reference },
		{ _field_tag_reference, "game engine globals", &game_engine_globals_reference },
		{ _field_tag_reference, "multiplayer globals", &multiplayer_globals_reference },
		{ _field_tag_reference, "survival_mode globals", &survival_mode_globals_reference },
		{ _field_tag_reference, "firefight globals", &firefight_globals_reference },
		{ _field_tag_reference, "global multiplayer object type list", &global_multiplayer_object_type_list_reference },
		{ _field_tag_reference, "custom app globals", &global_custom_app_globals_reference },
		{ _field_tag_reference, "grenades", &Tag::Reference<struct GameGlobalsGrenadeList>::s_defaultDefinition },
		{ _field_tag_reference, "ordnances", &Tag::Reference<struct GameGlobalsOrdnance>::s_defaultDefinition },
		{ _field_tag_reference, "silent assist", &Tag::Reference<struct SilentAssistGlobals>::s_defaultDefinition },
		{ _field_block, "cinematics globals", &cinematics_globals_block },
		{ _field_block, "campaign metagame globals", &campaign_metagame_globals_block },
		{ _field_tag_reference, "game medal globals", &game_medal_globals_reference },
		{ _field_struct, "language pack1", &language_pack_definition },
		{ _field_struct, "language pack2", &language_pack_definition },
		{ _field_struct, "language pack3", &language_pack_definition },
		{ _field_struct, "language pack4", &language_pack_definition },
		{ _field_struct, "language pack5", &language_pack_definition },
		{ _field_struct, "language pack6", &language_pack_definition },
		{ _field_struct, "language pack7", &language_pack_definition },
		{ _field_struct, "language pack8", &language_pack_definition },
		{ _field_struct, "language pack9", &language_pack_definition },
		{ _field_struct, "language pack10", &language_pack_definition },
		{ _field_struct, "language pack11", &language_pack_definition },
		{ _field_struct, "language pack12", &language_pack_definition },
		{ _field_struct, "language pack13", &language_pack_definition },
		{ _field_struct, "language pack14", &language_pack_definition },
		{ _field_struct, "language pack15", &language_pack_definition },
		{ _field_struct, "language pack16", &language_pack_definition },
		{ _field_struct, "language pack17", &language_pack_definition },
		{ _field_explanation, "Rasterizer globals", "" },
		{ _field_tag_reference, "rasterizer_globals_ref", &global_rasterizer_globals_reference },
		{ _field_explanation, "Default camera fx settings", "" },
		{ _field_tag_reference, "default camera fx settings", &global_camera_fx_settings_reference },
		{ _field_explanation, "Default wind settings", "" },
		{ _field_tag_reference, "default wind settings", &global_wind_reference },
		{ _field_explanation, "Weather globals", "" },
		{ _field_tag_reference, "weather globals", &global_weather_globals_reference },
		{ _field_explanation, "Default collision damage", "" },
		{ _field_tag_reference, "collision damage effect", &global_damage_reference },
		{ _field_tag_reference, "collision damage", &collision_damage_reference$5 },
		{ _field_explanation, "global material types", "" },
		{ _field_string_id, "global water material", "the default value for what material type water is" },
		{ _field_string_id, "global air material", "the default value for what material type air is" },
		{ _field_short_integer, "global water material type" },
		{ _field_short_integer, "global air material type" },
		{ _field_tag_reference, "effect globals", &global_effect_globals_reference },
		{ _field_tag_reference, "havok collision filter", &havok_collision_filter_reference },
		{ _field_tag_reference, "default item grounded friction", &global_grounded_friction_reference },
		{ _field_block, "active camo", &active_camo_globals_block },
		{ _field_tag_reference, "incident global properties", &incident_global_properties_definition_reference },
		{ _field_tag_reference, "player grade globals", &player_grade_globals_definition_reference },
		{ _field_tag_reference, "enlistment globals", &player_enlistment_globals_definition_reference },
		{ _field_tag_reference, "player model customization globals", &global_player_model_customization_globals_reference },
		{ _field_tag_reference, "loadout globals", &global_loadout_globals_reference },
		{ _field_tag_reference, "challenge globals", &challenge_globals_definition_reference },
		{ _field_tag_reference, "game completion rewards globals", &game_completion_rewards_globals_reference },
		{ _field_tag_reference, "game achievements", &achievements_reference },
		{ _field_tag_reference, "game avatar awards", &avatar_awards_reference },
		{ _field_tag_reference, "game performance thortles default", &game_performance_throttle_reference },
		{ _field_tag_reference, "armormod globals", &armormod_globals_reference },
		{ _field_tag_reference, "progression globals", &global_progression_reference },
		{ _field_block, "garbage collection", &garbage_collection_block },
		{ _field_block, "camera impulse", &global_camera_impulse_block },
		{ _field_block, "runtime materials", &runtime_materials_block },
		{ _field_block, "Hologram Lighting", &hologramLightingGlobalsBlock_block },
		{ _field_tag_reference, "Narrative globals", &NarrativeGlobalsReference },
		{ _field_terminator }
	};

	#define PATCH_GLOBALS_STRUCT_DEFINITION_ID { 0x61508392, 0x3EAD42E3, 0x8EC54AE9, 0xD301A46B }
	TAG_STRUCT(
		patch_globals_struct_definition,
		"patch_globals_struct_definition",
		"PatchGlobals",
		PATCH_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "language pack1", &language_pack_definition },
		{ _field_struct, "language pack2", &language_pack_definition },
		{ _field_struct, "language pack3", &language_pack_definition },
		{ _field_struct, "language pack4", &language_pack_definition },
		{ _field_struct, "language pack5", &language_pack_definition },
		{ _field_struct, "language pack6", &language_pack_definition },
		{ _field_struct, "language pack7", &language_pack_definition },
		{ _field_struct, "language pack8", &language_pack_definition },
		{ _field_struct, "language pack9", &language_pack_definition },
		{ _field_struct, "language pack10", &language_pack_definition },
		{ _field_struct, "language pack11", &language_pack_definition },
		{ _field_struct, "language pack12", &language_pack_definition },
		{ _field_struct, "language pack13", &language_pack_definition },
		{ _field_struct, "language pack14", &language_pack_definition },
		{ _field_struct, "language pack15", &language_pack_definition },
		{ _field_struct, "language pack16", &language_pack_definition },
		{ _field_struct, "language pack17", &language_pack_definition },
		{ _field_terminator }
	};

	#define ELITE_SPECULAR_COLOR_STRUCT_ID { 0x19358444, 0x61AC41D0, 0x8B134E19, 0x26C63A1B }
	TAG_STRUCT(
		elite_specular_color_struct,
		"elite_specular_color_struct",
		"s_elite_specular_color",
		ELITE_SPECULAR_COLOR_STRUCT_ID)
	{
		{ _field_real_rgb_color, "tertiary color" },
		{ _field_real_rgb_color, "quaternary color" },
		{ _field_terminator }
	};

	STRINGS(language_enum)
	{
		"english",
		"japanese",
		"german",
		"french",
		"spanish",
		"mexican spanish",
		"italian",
		"korean",
		"chinese-traditional",
		"chinese-simplified",
		"portuguese",
		"polish",
		"russian",
		"danish",
		"finnish",
		"dutch",
		"norwegian"
	};
	STRING_LIST(language_enum, language_enum_strings, _countof(language_enum_strings));

} // namespace macaque

} // namespace blofeld
