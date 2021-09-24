#pragma once

namespace blofeld
{



	constexpr unsigned long SOUND_EFFECT_TEMPLATE_TAG = '<fx>';
	extern s_tag_group sound_effect_template_group; // sound_effect_template_block


	extern s_tag_block_definition sound_effect_template_block;
	extern s_tag_block_definition sound_effect_templates_block;
	extern s_tag_struct_definition sound_effect_templates_block_struct_definition; // sound_effect_templates_block
	extern s_tag_block_definition sound_effect_template_parameter_block;
	extern s_tag_struct_definition sound_effect_template_parameter_block_struct_definition; // sound_effect_template_parameter_block
	extern s_tag_block_definition sound_effect_template_additional_sound_input_block;
	extern s_tag_struct_definition sound_effect_template_additional_sound_input_block_struct_definition; // sound_effect_template_additional_sound_input_block

	extern s_tag_struct_definition sound_effect_template_struct_definition; // tag group

	extern s_string_list_definition sound_effect_template_type_enum_definition;
	extern s_string_list_definition sound_effect_template_parameter_flags_definition;
	extern s_string_list_definition sound_effect_template_flags_definition;



} // namespace blofeld

