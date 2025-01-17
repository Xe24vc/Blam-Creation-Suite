#pragma once

namespace blofeld
{



	constexpr unsigned long CUI_LOGIC_TAG = 'culo';
	extern s_tag_group cui_logic_group; // cui_logic_block

	constexpr unsigned long CUI_SCREEN_TAG = 'cusc';
	extern s_tag_group cui_screen_group; // cui_screen_block

	constexpr unsigned long CUI_STATIC_DATA_TAG = 'cust';
	extern s_tag_group cui_static_data_group; // cui_static_data_block


	extern s_tag_block_definition cui_logic_block;
	extern s_tag_block_definition cui_screen_block;
	extern s_tag_block_definition cui_static_data_block;
	extern s_tag_block_definition template_instantiation_block_definition_block;
	extern s_tag_struct_definition template_instantiation_block_definition_block_struct_definition; // template_instantiation_block_definition_block
	extern s_tag_block_definition component_definition_block;
	extern s_tag_struct_definition component_definition_block_struct_definition; // component_definition_block
	extern s_tag_block_definition component_index_block_definition_block;
	extern s_tag_struct_definition component_index_block_definition_block_struct_definition; // component_index_block_definition_block
	extern s_tag_block_definition overlay_definition_block;
	extern s_tag_struct_definition overlay_definition_block_struct_definition; // overlay_definition_block
	extern s_tag_block_definition component_properties_definition_block;
	extern s_tag_struct_definition component_properties_definition_block_struct_definition; // component_properties_definition_block
	extern s_tag_block_definition property_long_value_block;
	extern s_tag_struct_definition property_long_value_block_struct_definition; // property_long_value_block
	extern s_tag_block_definition property_real_value_block;
	extern s_tag_struct_definition property_real_value_block_struct_definition; // property_real_value_block
	extern s_tag_block_definition property_string_id_value_block;
	extern s_tag_struct_definition property_string_id_value_block_struct_definition; // property_string_id_value_block
	extern s_tag_block_definition propertyComponentPtrValue_block;
	extern s_tag_struct_definition propertyComponentPtrValue_block_struct_definition; // propertyComponentPtrValue_block
	extern s_tag_block_definition property_tag_reference_value_block;
	extern s_tag_struct_definition property_tag_reference_value_block_struct_definition; // property_tag_reference_value_block
	extern s_tag_block_definition property_text_value_block;
	extern s_tag_struct_definition property_text_value_block_struct_definition; // property_text_value_block
	extern s_tag_block_definition property_argb_color_value_block;
	extern s_tag_struct_definition property_argb_color_value_block_struct_definition; // property_argb_color_value_block
	extern s_tag_block_definition animation_definition_block;
	extern s_tag_struct_definition animation_definition_block_struct_definition; // animation_definition_block
	extern s_tag_block_definition animation_component_definition_block;
	extern s_tag_struct_definition animation_component_definition_block_struct_definition; // animation_component_definition_block
	extern s_tag_block_definition animation_component_real_property_block;
	extern s_tag_struct_definition animation_component_real_property_block_struct_definition; // animation_component_real_property_block
	extern s_tag_block_definition animation_property_keyframe_real_value_block;
	extern s_tag_struct_definition animation_property_keyframe_real_value_block_struct_definition; // animation_property_keyframe_real_value_block
	extern s_tag_block_definition animation_component_argb_color_property_block;
	extern s_tag_struct_definition animation_component_argb_color_property_block_struct_definition; // animation_component_argb_color_property_block
	extern s_tag_block_definition animation_property_keyframe_argb_color_value_block;
	extern s_tag_struct_definition animation_property_keyframe_argb_color_value_block_struct_definition; // animation_property_keyframe_argb_color_value_block
	extern s_tag_block_definition overlay_editor_only_definition_block;
	extern s_tag_struct_definition overlay_editor_only_definition_block_struct_definition; // overlay_editor_only_definition_block
	extern s_tag_block_definition component_editor_only_definition_block;
	extern s_tag_struct_definition component_editor_only_definition_block_struct_definition; // component_editor_only_definition_block
	extern s_tag_block_definition property_editor_only_definition_block;
	extern s_tag_struct_definition property_editor_only_definition_block_struct_definition; // property_editor_only_definition_block
	extern s_tag_block_definition animation_editor_only_definition_block;
	extern s_tag_struct_definition animation_editor_only_definition_block_struct_definition; // animation_editor_only_definition_block
	extern s_tag_block_definition property_binding_block;
	extern s_tag_struct_definition property_binding_block_struct_definition; // property_binding_block
	extern s_tag_block_definition binding_conversion_long_comparison_block_definition_block;
	extern s_tag_struct_definition binding_conversion_long_comparison_block_definition_block_struct_definition; // binding_conversion_long_comparison_block_definition_block
	extern s_tag_block_definition static_data_table_block;
	extern s_tag_struct_definition static_data_table_block_struct_definition; // static_data_table_block
	extern s_tag_block_definition static_data_column_block;
	extern s_tag_struct_definition static_data_column_block_struct_definition; // static_data_column_block
	extern s_tag_block_definition static_data_row_block;
	extern s_tag_block_definition expression_block;
	extern s_tag_struct_definition expression_block_struct_definition; // expression_block
	extern s_tag_block_definition expression_step_block;
	extern s_tag_struct_definition expression_step_block_struct_definition; // expression_step_block
	extern s_tag_block_definition encapsulatedProperties_block;
	extern s_tag_struct_definition encapsulatedProperties_block_struct_definition; // encapsulatedProperties_block
	extern s_tag_block_definition string_file_references_block;
	extern s_tag_struct_definition string_file_references_block_struct_definition; // string_file_references_block

	extern s_tag_struct_definition cui_logic_struct_definition; // tag group
	extern s_tag_struct_definition cui_screen_struct_definition; // tag group
	extern s_tag_struct_definition cui_static_data_struct_definition; // tag group
	extern s_tag_struct_definition cui_system;
	extern s_tag_struct_definition properties_struct;
	extern s_tag_struct_definition animation_scalar_function;
	extern s_tag_struct_definition static_data_struct;

	extern s_string_list_definition propertyComponentPtrFlags;
	extern s_string_list_definition property_type;
	extern s_string_list_definition property_binding_flags;
	extern s_string_list_definition binding_conversion_function_enum_definition;
	extern s_string_list_definition binding_conversion_comparison_operator_enum_definition;
	extern s_string_list_definition animation_property_composition_type;
	extern s_string_list_definition animation_property_flags;
	extern s_string_list_definition animationInputType;
	extern s_string_list_definition step_type;
	extern s_string_list_definition step_operator;
	extern s_string_list_definition step_variable;
	extern s_string_list_definition component_definition_flags;
	extern s_string_list_definition editor_overlay_info_flags;
	extern s_string_list_definition editor_property_info_flags;



} // namespace blofeld

