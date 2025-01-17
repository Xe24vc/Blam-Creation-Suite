#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		communication_sounds_group,
		COMMUNICATION_SOUNDS_TAG,
		nullptr,
		INVALID_TAG,
		communication_sounds_block );

	TAG_BLOCK_FROM_STRUCT(
		communication_sounds_block,
		"communication_sounds_block",
		1,
		communication_sounds_struct_definition);

	#define COMMUNICATION_SOUNDS_STRUCT_DEFINITION_ID { 0x9889948D, 0xAC0D4FD5, 0x8157FA51, 0xF5BC8577 }
	TAG_STRUCT_V6(
		communication_sounds_struct_definition,
		"communication_sounds_struct_definition",
		"s_communication_sound_group",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COMMUNICATION_SOUNDS_STRUCT_DEFINITION_ID)
	{
		{ _field_tag_reference, "silence", &global_sound_reference },
		{ _field_tag_reference, "alert_holding", &global_sound_reference },
		{ _field_tag_reference, "enemy_1_enemy", &global_sound_reference },
		{ _field_tag_reference, "enemy_2_enemy", &global_sound_reference },
		{ _field_tag_reference, "enemy_3_enemy", &global_sound_reference },
		{ _field_tag_reference, "enemy_many_enemies", &global_sound_reference },
		{ _field_tag_reference, "enemy_vehicle", &global_sound_reference },
		{ _field_tag_reference, "enemy_many_vehicles", &global_sound_reference },
		{ _field_tag_reference, "enemy_tank", &global_sound_reference },
		{ _field_tag_reference, "enemy_many_tanks", &global_sound_reference },
		{ _field_tag_reference, "enemy_banshee", &global_sound_reference },
		{ _field_tag_reference, "enemy_falcon", &global_sound_reference },
		{ _field_tag_reference, "enemy_ghost", &global_sound_reference },
		{ _field_tag_reference, "enemy_wraith", &global_sound_reference },
		{ _field_tag_reference, "enemy_scorpion", &global_sound_reference },
		{ _field_tag_reference, "enemy_mongoose", &global_sound_reference },
		{ _field_tag_reference, "alert_backup", &global_sound_reference },
		{ _field_tag_reference, "loc_dummy", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_bfghill", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_bfgramp", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_bfgwater", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_cliffarch", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_covybridge", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_covycore", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_covytower", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_hillside", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_powerarch", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_powerhouse", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_powerinside", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_powerpipe", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_rock", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_spartanbarn", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_spartanbarnroof", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_spartancore", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_spartancoreroof", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_spartandam", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_spartanhigh", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_spartantower", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_stationbridge", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_upperdeck", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_waterbridge", &global_sound_reference },
		{ _field_tag_reference, "loc_ph_waterside", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_beachside", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_bfg", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_cave", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_cliffside", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_covbase", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_covgen", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_covside", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_crack", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_middle", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_spartanbase", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_spartancore", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_spartangen", &global_sound_reference },
		{ _field_tag_reference, "loc_sl_spartanside", &global_sound_reference },
		{ _field_tag_reference, "loc_af_aft_connector", &global_sound_reference },
		{ _field_tag_reference, "loc_af_aft_vault", &global_sound_reference },
		{ _field_tag_reference, "loc_af_central_catwalk", &global_sound_reference },
		{ _field_tag_reference, "loc_af_central_thing", &global_sound_reference },
		{ _field_tag_reference, "loc_af_coil_access", &global_sound_reference },
		{ _field_tag_reference, "loc_af_forward_catwalk", &global_sound_reference },
		{ _field_tag_reference, "loc_af_forward_compartment", &global_sound_reference },
		{ _field_tag_reference, "loc_af_in_space", &global_sound_reference },
		{ _field_tag_reference, "loc_af_ninja_rail", &global_sound_reference },
		{ _field_tag_reference, "loc_af_port_catwalk", &global_sound_reference },
		{ _field_tag_reference, "loc_af_port_floor", &global_sound_reference },
		{ _field_tag_reference, "loc_af_port_mancannon", &global_sound_reference },
		{ _field_tag_reference, "loc_af_port_observation", &global_sound_reference },
		{ _field_tag_reference, "loc_af_port_side", &global_sound_reference },
		{ _field_tag_reference, "loc_af_spine", &global_sound_reference },
		{ _field_tag_reference, "loc_af_starboard_catwalk", &global_sound_reference },
		{ _field_tag_reference, "loc_af_starboard_floor", &global_sound_reference },
		{ _field_tag_reference, "loc_af_starboard_mancannon", &global_sound_reference },
		{ _field_tag_reference, "loc_af_starboard_observation", &global_sound_reference },
		{ _field_tag_reference, "loc_af_starboard_side", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_atrium", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_atrium_floor", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_atrium_ramp", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_back_hallway", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_back_pocket", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_back_stairs", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_blue_lift", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_break_room", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_cic_entrance", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_cic_hall", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_cic_ramp", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_command_information_center", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_elbow", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_green_lift", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_green_lift_entrance", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_hangar", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_hangar_bridge", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_high_balcony", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_high_bridge", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_high_perch", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_high_stairs", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_locker_room", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_lounge", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_lounge_balcony", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_lower_elevator_hall", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_low_bridge", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_midlevel", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_mid_bridge", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_mountainview_room", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_small_ramp", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_sword_room", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_upper_elevator_hall", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_waiting_room", &global_sound_reference },
		{ _field_tag_reference, "loc_se_air", &global_sound_reference },
		{ _field_tag_reference, "loc_se_back_door", &global_sound_reference },
		{ _field_tag_reference, "loc_se_back_path", &global_sound_reference },
		{ _field_tag_reference, "loc_se_below_deck", &global_sound_reference },
		{ _field_tag_reference, "loc_se_bighouse_high", &global_sound_reference },
		{ _field_tag_reference, "loc_se_bighouse_mid", &global_sound_reference },
		{ _field_tag_reference, "loc_se_bighouse_observation", &global_sound_reference },
		{ _field_tag_reference, "loc_se_blockhouse", &global_sound_reference },
		{ _field_tag_reference, "loc_se_blockhouse_bridge", &global_sound_reference },
		{ _field_tag_reference, "loc_se_blockhouse_roof", &global_sound_reference },
		{ _field_tag_reference, "loc_se_bridge", &global_sound_reference },
		{ _field_tag_reference, "loc_se_center", &global_sound_reference },
		{ _field_tag_reference, "loc_se_comms_roof", &global_sound_reference },
		{ _field_tag_reference, "loc_se_comms_shack", &global_sound_reference },
		{ _field_tag_reference, "loc_se_comms_stairs", &global_sound_reference },
		{ _field_tag_reference, "loc_se_deck", &global_sound_reference },
		{ _field_tag_reference, "loc_se_destroyed_house", &global_sound_reference },
		{ _field_tag_reference, "loc_se_east_cliff", &global_sound_reference },
		{ _field_tag_reference, "loc_se_high_bridge", &global_sound_reference },
		{ _field_tag_reference, "loc_se_locker_room", &global_sound_reference },
		{ _field_tag_reference, "loc_se_locker_stairs", &global_sound_reference },
		{ _field_tag_reference, "loc_se_main_ring", &global_sound_reference },
		{ _field_tag_reference, "loc_se_mud", &global_sound_reference },
		{ _field_tag_reference, "loc_se_off_the_edge", &global_sound_reference },
		{ _field_tag_reference, "loc_se_patio", &global_sound_reference },
		{ _field_tag_reference, "loc_se_pipes_high", &global_sound_reference },
		{ _field_tag_reference, "loc_se_pipes_low", &global_sound_reference },
		{ _field_tag_reference, "loc_se_pipe_stairs", &global_sound_reference },
		{ _field_tag_reference, "loc_se_ridge", &global_sound_reference },
		{ _field_tag_reference, "loc_se_road", &global_sound_reference },
		{ _field_tag_reference, "loc_se_rock_garden", &global_sound_reference },
		{ _field_tag_reference, "loc_se_showers", &global_sound_reference },
		{ _field_tag_reference, "loc_se_spillway", &global_sound_reference },
		{ _field_tag_reference, "loc_se_spillway_arch", &global_sound_reference },
		{ _field_tag_reference, "loc_se_spillway_debris", &global_sound_reference },
		{ _field_tag_reference, "loc_se_staffroom", &global_sound_reference },
		{ _field_tag_reference, "loc_se_staffroom_roof", &global_sound_reference },
		{ _field_tag_reference, "loc_se_stone_arch", &global_sound_reference },
		{ _field_tag_reference, "loc_se_stone_bridge", &global_sound_reference },
		{ _field_tag_reference, "loc_se_storage", &global_sound_reference },
		{ _field_tag_reference, "loc_se_storage_ramp", &global_sound_reference },
		{ _field_tag_reference, "loc_se_water", &global_sound_reference },
		{ _field_tag_reference, "loc_se_waterfall", &global_sound_reference },
		{ _field_tag_reference, "loc_se_west_cliff", &global_sound_reference },
		{ _field_tag_reference, "loc_se_yard", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_CIC", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_vestibule", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_processing", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_windowbridge", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_greathall", &global_sound_reference },
		{ _field_tag_reference, "loc_sb_vent", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_catwalk", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_leftstairs", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_rightstairs", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_leftvent", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_rightvent", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_tunnel", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_mainlift", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_liftaccess", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_liftroom", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_leftplatform", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_rightplatform", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_highbalconyright", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_highbalconyleft", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_observation", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_rightroom", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_leftroom", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_bigplatform", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_leftelevator", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_rightelevator", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_topwalkway", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_midwalkway", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_lowwalkway", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_lowbalconyleft", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_lowbalconyright", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_lowmiddle", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_highmiddle", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_highright", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_highleft", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_floor", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_outside", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_leftside", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_rightside", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_gantry", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_sabre", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_center", &global_sound_reference },
		{ _field_tag_reference, "loc_ls_outofbounds", &global_sound_reference },
		{ _field_tag_reference, "loc_se_southbridge", &global_sound_reference },
		{ _field_tag_reference, "loc_se_southarch", &global_sound_reference },
		{ _field_tag_reference, "loc_se_northbridge", &global_sound_reference },
		{ _field_tag_reference, "loc_se_northarch", &global_sound_reference },
		{ _field_tag_reference, "loc_se_bighouselow", &global_sound_reference },
		{ _field_tag_reference, "loc_se_bighousesteps", &global_sound_reference },
		{ _field_tag_reference, "loc_se_bunkhouseroof", &global_sound_reference },
		{ _field_tag_reference, "loc_se_bunkhouse", &global_sound_reference },
		{ _field_tag_reference, "loc_se_pipes", &global_sound_reference },
		{ _field_tag_reference, "loc_se_transformers", &global_sound_reference },
		{ _field_tag_reference, "loc_se_eastpath", &global_sound_reference },
		{ _field_tag_reference, "loc_se_northside", &global_sound_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE_GROUP(global_sound_reference, _tag_reference_flag_resolved_by_game)
	{
		SOUND_COMBINER_TAG,
		SOUND_OLD_TAG,
		SOUND_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE_GROUP(global_sound_and_looping_sound_reference, _tag_reference_flag_resolved_by_game)
	{
		SOUND_COMBINER_TAG,
		SOUND_OLD_TAG,
		SOUND_LOOPING_TAG,
		SOUND_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(global_soundbank_reference, SOUNDBANK_TAG, _tag_reference_flag_resolved_by_game);

	TAG_REFERENCE(global_looping_sound_reference, SOUND_LOOPING_TAG, _tag_reference_flag_resolved_by_game);

	TAG_REFERENCE_GROUP(global_force_sound_only_reference, _tag_reference_flag_resolved_by_game)
	{
		SOUND_OLD_TAG,
		SOUND_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(global_sound_effect_collection_reference, SOUND_EFFECT_COLLECTION_TAG);

	TAG_REFERENCE(global_communication_sound_group_reference, COMMUNICATION_SOUNDS_TAG);



} // namespace blofeld

