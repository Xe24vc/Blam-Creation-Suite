#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long MULTIPLAYER_GLOBALS_TAG = 'mulg';
	extern s_tag_group multiplayer_globals_group; // multiplayer_globals_block

	extern s_tag_struct_definition multiplayer_unknown_block_block_struct;
	extern s_tag_struct_definition multiplayer_constants_unknown_struct_struct_definition;
	extern s_tag_struct_definition multiplayer_constants_weapon_block_block_struct;
	extern s_tag_struct_definition multiplayer_constants_vehicle_block_block_struct;
	extern s_tag_struct_definition multiplayer_constants_projectile_block_block_struct;

	extern s_tag_block_definition multiplayer_globals_block;
	extern s_tag_block_definition spawn_influence_weight_falloff_function_block;
	extern s_tag_struct_definition spawn_influence_weight_falloff_function_block_struct_definition; // spawn_influence_weight_falloff_function_block
	extern s_tag_block_definition multiplayer_universal_block;
	extern s_tag_struct_definition multiplayer_universal_block_struct_definition; // multiplayer_universal_block
	extern s_tag_block_definition teamDefinitionBlock_block;
	extern s_tag_struct_definition teamDefinitionBlock_block_struct_definition; // teamDefinitionBlock_block
	extern s_tag_block_definition requisition_constants_block;
	extern s_tag_struct_definition requisition_constants_block_struct_definition; // requisition_constants_block
	extern s_tag_block_definition requisition_palette_block;
	extern s_tag_struct_definition requisition_palette_block_struct_definition; // requisition_palette_block
	extern s_tag_block_definition multiplayer_runtime_block;
	extern s_tag_struct_definition multiplayer_runtime_block_struct_definition; // multiplayer_runtime_block
	extern s_tag_block_definition sounds_block;
	extern s_tag_struct_definition sounds_block_struct_definition; // sounds_block
	extern s_tag_block_definition looping_sounds_block;
	extern s_tag_struct_definition looping_sounds_block_struct_definition; // looping_sounds_block
	extern s_tag_block_definition multiplayer_constants_block;
	extern s_tag_struct_definition multiplayer_constants_block_struct_definition; // multiplayer_constants_block
	extern s_tag_block_definition game_engine_status_response_block;
	extern s_tag_struct_definition game_engine_status_response_block_struct_definition; // game_engine_status_response_block
	extern s_tag_block_definition multiplayer_color_block$3_block;
	extern s_tag_struct_definition multiplayer_color_block$3_block_struct_definition; // multiplayer_color_block$3_block

	extern s_tag_struct_definition multiplayer_globals_struct_definition; // tag group

	extern c_versioned_string_list requisition_special_buy_enum_strings;
	extern s_string_list_definition requisition_special_buy_enum;
	extern c_versioned_string_list emblemInfoFlags_strings;
	extern s_string_list_definition emblemInfoFlags;
	extern c_versioned_string_list playerColorEnum_strings;
	extern s_string_list_definition playerColorEnum;
	extern c_versioned_string_list game_engine_status_enum_definition_strings;
	extern s_string_list_definition game_engine_status_enum_definition;
	extern c_versioned_string_list game_engine_status_flags_definition_strings;
	extern s_string_list_definition game_engine_status_flags_definition;


} // namespace macaque

} // namespace blofeld

