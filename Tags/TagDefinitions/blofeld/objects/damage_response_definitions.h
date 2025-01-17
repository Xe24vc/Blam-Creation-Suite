#pragma once

namespace blofeld
{



	constexpr unsigned long DAMAGE_RESPONSE_DEFINITION_TAG = 'drdf';
	extern s_tag_group damage_response_definition_group; // damage_response_definition_block


	extern s_tag_block_definition damage_response_definition_block;
	extern s_tag_block_definition damage_response_class_block;
	extern s_tag_struct_definition damage_response_class_block_struct_definition; // damage_response_class_block
	extern s_tag_block_definition damage_response_global_sound_effect_block;
	extern s_tag_struct_definition damage_response_global_sound_effect_block_struct_definition; // damage_response_global_sound_effect_block
	extern s_tag_block_definition area_control_block;
	extern s_tag_struct_definition area_control_block_struct_definition; // area_control_block

	extern s_tag_struct_definition damage_response_definition_struct_definition; // tag group
	extern s_tag_struct_definition damage_response_directional_flash_struct;
	extern s_tag_struct_definition damage_response_motion_sensor_ping;
	extern s_tag_struct_definition area_control_scalar_function_struct;
	extern s_tag_struct_definition area_control_scalar_object_function_struct;

	extern s_string_list_definition area_control_flags;
	extern s_string_list_definition damage_response_class_type_enum;
	extern s_string_list_definition damage_response_class_flags;

	extern s_tag_reference_definition global_damage_effect_or_response_definition_reference;
	extern s_tag_reference_definition global_damage_response_definition_reference;



} // namespace blofeld

