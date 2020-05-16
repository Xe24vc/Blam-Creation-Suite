#pragma once

namespace blofeld
{

constexpr unsigned long SOUND_EFFECT_COLLECTION_TAG = 'sfx+';

extern s_tag_struct sound_effect_collection_block_struct;
extern s_tag_block_definition sound_effect_collection_block;
extern s_tag_group sound_effect_collection_group;

extern s_tag_struct platform_sound_playback_block_block_struct;
extern s_tag_block_definition platform_sound_playback_block_block;
extern s_tag_struct platform_sound_playback_lowpass_block_block_struct;
extern s_tag_block_definition platform_sound_playback_lowpass_block_block;
extern s_tag_struct platform_sound_playback_component_block_block_struct;
extern s_tag_block_definition platform_sound_playback_component_block_block;

extern s_tag_struct platform_sound_playback_struct_struct_definition;

} // namespace blofeld
