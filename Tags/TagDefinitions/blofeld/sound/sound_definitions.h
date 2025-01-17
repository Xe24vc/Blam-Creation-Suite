#pragma once

namespace blofeld
{
	constexpr unsigned long SOUND_MIX_MASTERING_TAG = 'snmm';
	extern s_tag_group sound_mix_mastering_group; // #CUSTOM
	extern s_tag_block_definition sound_mix_mastering_block; // #CUSTOM
	extern s_tag_struct_definition sound_mix_mastering_block_struct_definition; // #CUSTOM
	extern s_tag_struct_definition sound_mix_equalizer_struct_definition; // #CUSTOM

	constexpr unsigned long SOUNDBANK_TAG = 'sbnk';
	extern s_tag_group soundbank_group; // soundbank_block
	extern s_tag_block_definition soundbank_block;
	extern s_tag_struct_definition soundbank_block_struct_definition; // soundbank_block

	constexpr unsigned long SOUND_GLOBAL_PROPAGATION_TAG = 'sgp!';
	extern s_tag_group sound_global_propagation_group; // sound_global_propagation_block
	extern s_tag_block_definition sound_global_propagation_block;
	extern s_tag_struct_definition sound_global_propagation_block_struct_definition; // sound_global_propagation_block

	constexpr unsigned long SOUND_TAG = 'snd!';
	extern s_tag_group sound_group; // sound_block
	extern s_tag_block_definition sound_block;
	extern s_tag_struct_definition sound_block_struct_definition; // sound_block

	constexpr unsigned long SOUND_OLD_TAG = 'sndo';
	extern s_tag_group sound_old_group; // sound_old_block
	extern s_tag_block_definition sound_old_block;
	extern s_tag_struct_definition sound_old_block_struct_definition; // sound_old_block

	constexpr unsigned long SOUND2_TAG = 'sndx';
	extern s_tag_group sound2_group; // sound2_block
	extern s_tag_block_definition sound2_block;
	extern s_tag_struct_definition sound2_block_struct_definition; // sound2_block

	constexpr unsigned long SOUND_MIX_TAG = 'snmx';
	extern s_tag_group sound_mix_group; // sound_mix_block
	extern s_tag_block_definition sound_mix_block;
	extern s_tag_struct_definition sound_mix_block_struct_definition; // sound_mix_block

	constexpr unsigned long SOUND_DIALOGUE_CONSTANTS_TAG = 'spk!';
	extern s_tag_group sound_dialogue_constants_group; // sound_dialogue_constants_block


	extern s_tag_block_definition sound_dialogue_constants_block;
	extern s_tag_block_definition sound_globals_block;
	extern s_tag_struct_definition sound_globals_block_struct_definition; // sound_globals_block
	extern s_tag_block_definition StreamingPackBlock_block;
	extern s_tag_struct_definition StreamingPackBlock_block_struct_definition; // StreamingPackBlock_block
	extern s_tag_block_definition campaign_unspatialized_sounds_block;
	extern s_tag_struct_definition campaign_unspatialized_sounds_block_struct_definition; // campaign_unspatialized_sounds_block
	extern s_tag_block_definition SoundBankBlock_block;
	extern s_tag_struct_definition SoundBankBlock_block_struct_definition; // SoundBankBlock_block
	extern s_tag_block_definition soundLipSyncInfoBlock_block;
	extern s_tag_block_definition deterministicSpeechEventBlock_block;
	extern s_tag_block_definition facial_animation_language_block;
	extern s_tag_struct_definition facial_animation_language_block_struct_definition; // facial_animation_language_block
	extern s_tag_block_definition sound_promotion_rule_block;
	extern s_tag_struct_definition sound_promotion_rule_block_struct_definition; // sound_promotion_rule_block
	extern s_tag_block_definition sound_pitch_range_block;
	extern s_tag_struct_definition sound_pitch_range_block_struct_definition; // sound_pitch_range_block
	extern s_tag_block_definition sound_permutations_block;
	extern s_tag_struct_definition sound_permutations_block_struct_definition; // sound_permutations_block
	extern s_tag_block_definition sound_permutation_languages_block;
	extern s_tag_struct_definition sound_permutation_languages_block_struct_definition; // sound_permutation_languages_block
	extern s_tag_block_definition sound_permutation_chunk_block;
	extern s_tag_struct_definition sound_permutation_chunk_block_struct_definition; // sound_permutation_chunk_block
	extern s_tag_block_definition sound_promotion_runtime_timer_block;
	extern s_tag_struct_definition sound_promotion_runtime_timer_block_struct_definition; // sound_promotion_runtime_timer_block
	extern s_tag_block_definition sound_platform_sound_playback_block;
	extern s_tag_struct_definition sound_platform_sound_playback_block_struct_definition; // sound_platform_sound_playback_block
	extern s_tag_block_definition sound_extra_info_block;
	extern s_tag_struct_definition sound_extra_info_block_struct_definition; // sound_extra_info_block
	extern s_tag_block_definition sound_definition_language_permutation_info_block;
	extern s_tag_struct_definition sound_definition_language_permutation_info_block_struct_definition; // sound_definition_language_permutation_info_block
	extern s_tag_block_definition sound_permutation_raw_info_block;
	extern s_tag_struct_definition sound_permutation_raw_info_block_struct_definition; // sound_permutation_raw_info_block
	extern s_tag_block_definition sound_permutation_marker_block;
	extern s_tag_struct_definition sound_permutation_marker_block_struct_definition; // sound_permutation_marker_block
	extern s_tag_block_definition sound_xma2_seek_table_block;
	extern s_tag_struct_definition sound_xma2_seek_table_block_struct_definition; // sound_xma2_seek_table_block
	extern s_tag_block_definition sound_pitch_range_distances_block;
	extern s_tag_block_definition facial_animation_permutation_block;
	extern s_tag_struct_definition facial_animation_permutation_block_struct_definition; // facial_animation_permutation_block
	extern s_tag_block_definition facial_animation_curve_block;
	extern s_tag_struct_definition facial_animation_curve_block_struct_definition; // facial_animation_curve_block

	extern s_tag_struct_definition sound_dialogue_constants_struct_definition; // tag group
	extern s_tag_struct_definition sound_distance_parameters_struct;
	extern s_tag_struct_definition sound_propagation_definition_struct;
	extern s_tag_struct_definition soundLipSyncInfoBlock_struct;
	extern s_tag_struct_definition deterministicSpeechEventBlock_struct;
	extern s_tag_struct_definition sound_playback_parameters_struct;
	extern s_tag_struct_definition sound_scale_modifiers_struct;
	extern s_tag_struct_definition sound_promotion_parameters_struct;
	extern s_tag_struct_definition sound_transmission_definition_struct;
	extern s_tag_struct_definition sound_stereo_mix_struct;
	extern s_tag_struct_definition sound_surround_mix_struct;
	extern s_tag_struct_definition sound_global_mix_struct;
	extern s_tag_struct_definition sound_center_mix_struct;
	extern s_tag_struct_definition sound_resource_definition_struct;
	extern s_tag_struct_definition facial_animation_resource_definition_struct;

	extern s_string_list_definition StreamingPackBlockFlags;
	extern s_string_list_definition sound_definition_flags;
	extern s_string_list_definition SoundEventDefinitionFlags;
	extern s_string_list_definition sound_import_flags;
	extern s_string_list_definition sound_pitch_range_internal_xsync_flags;
	extern s_string_list_definition sound_compression_enum;
	extern s_string_list_definition sound_encoding_enum;
	extern s_string_list_definition sound_sample_rate_enum;
	extern s_string_list_definition sound_effects_enum;
	extern s_string_list_definition sound_import_type_enum;
	extern s_string_list_definition sound_class_enum;
	extern s_string_list_definition sound_language_enum_definition;
	extern s_string_list_definition facial_animation_track_enum_definition;
	extern s_string_list_definition sound_permutation_flags;
	extern s_string_list_definition sound_permutation_external_flags;
	extern s_string_list_definition sound_override_location_flags_definition;
	extern s_string_list_definition sound_xsync_flags;
	extern s_string_list_definition SpeechEventInfoFlags;
	extern s_string_list_definition SoundBankDefinitionFlags;



} // namespace blofeld

