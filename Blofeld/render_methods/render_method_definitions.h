#pragma once

namespace blofeld
{

constexpr unsigned long RENDER_METHOD_TAG = 'rm  ';

extern s_tag_group render_method_group;
constexpr unsigned long RENDER_METHOD_DEFINITION_TAG = 'rmdf';

extern s_tag_group render_method_definition_group;
constexpr unsigned long RENDER_METHOD_OPTION_TAG = 'rmop';

extern s_tag_group render_method_option_group;
constexpr unsigned long RENDER_METHOD_TEMPLATE_TAG = 'rmt2';

extern s_tag_group render_method_template_group;

extern s_tag_block_definition render_method_block_block;
extern s_tag_block_definition render_method_definition_block_block;
extern s_tag_block_definition render_method_option_block_block;
extern s_tag_block_definition render_method_template_block_block;
extern s_tag_struct short_block_block_struct;
extern s_tag_block_definition short_block_block;
extern s_tag_struct render_method_parameter_block_block_struct;
extern s_tag_block_definition render_method_parameter_block_block;
extern s_tag_struct render_method_animated_parameter_block_block_struct;
extern s_tag_block_definition render_method_animated_parameter_block_block;
extern s_tag_struct render_method_postprocess_block_block_struct;
extern s_tag_block_definition render_method_postprocess_block_block;
extern s_tag_struct render_method_postprocess_texture_block_block_struct;
extern s_tag_block_definition render_method_postprocess_texture_block_block;
extern s_tag_struct real_vector4d_block_block_struct;
extern s_tag_block_definition real_vector4d_block_block;
extern s_tag_struct int_block_block_struct;
extern s_tag_block_definition int_block_block;
extern s_tag_struct tag_block_index_block_block_struct;
extern s_tag_block_definition tag_block_index_block_block;
extern s_tag_struct render_method_postprocess_pass_block_block_struct;
extern s_tag_block_definition render_method_postprocess_pass_block_block;
extern s_tag_struct render_method_routing_info_block_block_struct;
extern s_tag_block_definition render_method_routing_info_block_block;
extern s_tag_struct render_method_locked_parameter_block_block_struct;
extern s_tag_block_definition render_method_locked_parameter_block_block;
extern s_tag_struct render_method_category_block_block_struct;
extern s_tag_block_definition render_method_category_block_block;
extern s_tag_struct render_method_options_block_block_struct;
extern s_tag_block_definition render_method_options_block_block;
extern s_tag_struct render_method_entry_points_block_block_struct;
extern s_tag_block_definition render_method_entry_points_block_block;
extern s_tag_struct render_method_pass_block_block_struct;
extern s_tag_block_definition render_method_pass_block_block;
extern s_tag_struct render_method_pass_category_dependencies_block_struct;
extern s_tag_block_definition render_method_pass_category_dependencies_block;
extern s_tag_struct vertex_types_block_block_struct;
extern s_tag_block_definition vertex_types_block_block;
extern s_tag_struct render_method_option_parameter_block_block_struct;
extern s_tag_block_definition render_method_option_parameter_block_block;
extern s_tag_struct render_method_template_pass_block_block_struct;
extern s_tag_block_definition render_method_template_pass_block_block;
extern s_tag_struct render_method_template_constant_table_block_block_struct;
extern s_tag_block_definition render_method_template_constant_table_block_block;
extern s_tag_struct render_method_template_platform_block_block_struct;
extern s_tag_block_definition render_method_template_platform_block_block;

extern s_tag_struct render_method_struct_definition_struct_definition; // tag group
extern s_tag_struct render_method_definition_struct_definition_struct_definition; // tag group
extern s_tag_struct render_method_option_struct_definition_struct_definition; // tag group
extern s_tag_struct render_method_template_struct_definition_struct_definition; // tag group
extern s_tag_struct tag_block_index_struct_struct_definition;

} // namespace blofeld
