#pragma once

namespace blofeld
{

constexpr unsigned long MULTIPLAYER_VARIANT_SETTINGS_INTERFACE_DEFINITION_TAG = 'goof';

extern s_tag_group multiplayer_variant_settings_interface_definition_group;
constexpr unsigned long SANDBOX_TEXT_VALUE_PAIR_DEFINITION_TAG = 'jmrq';

extern s_tag_group sandbox_text_value_pair_definition_group;
constexpr unsigned long TEXT_VALUE_PAIR_DEFINITION_TAG = 'sily';

extern s_tag_group text_value_pair_definition_group;

extern s_tag_block_definition multiplayer_variant_settings_interface_definition_block_block;
extern s_tag_block_definition sandbox_text_value_pair_definition_block_block;
extern s_tag_block_definition text_value_pair_definition_block_block;
extern s_tag_struct variant_setting_edit_reference_block_block_struct;
extern s_tag_block_definition variant_setting_edit_reference_block_block;
extern s_tag_struct variant_option_block_block_struct;
extern s_tag_block_definition variant_option_block_block;
extern s_tag_struct sandbox_property_allowed_values_reference_block_block_struct;
extern s_tag_block_definition sandbox_property_allowed_values_reference_block_block;
extern s_tag_struct text_value_pair_reference_block_block_struct;
extern s_tag_block_definition text_value_pair_reference_block_block;

extern s_tag_struct multiplayer_variant_settings_interface_definition_struct_definition_struct_definition; // tag group
extern s_tag_struct sandbox_text_value_pair_definition_struct_definition_struct_definition; // tag group
extern s_tag_struct text_value_pair_definition_struct_definition_struct_definition; // tag group

} // namespace blofeld
