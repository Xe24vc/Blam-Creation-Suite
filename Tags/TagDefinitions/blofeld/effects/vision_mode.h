#pragma once

namespace blofeld
{



	constexpr unsigned long VISION_MODE_TAG = 'vmdx';
	extern s_tag_group vision_mode_group; // vision_mode_block


	extern s_tag_block_definition vision_mode_block;
	extern s_tag_block_definition visionModeScreenPassBlock_block;
	extern s_tag_struct_definition visionModeScreenPassBlock_block_struct_definition; // visionModeScreenPassBlock_block
	extern s_tag_block_definition visionModeEnvironmentPassBlock_block;
	extern s_tag_struct_definition visionModeEnvironmentPassBlock_block_struct_definition; // visionModeEnvironmentPassBlock_block
	extern s_tag_block_definition visionModeBipedPassesBlock_block;
	extern s_tag_struct_definition visionModeBipedPassesBlock_block_struct_definition; // visionModeBipedPassesBlock_block
	extern s_tag_block_definition visionModeBipedPassBlock_block;
	extern s_tag_struct_definition visionModeBipedPassBlock_block_struct_definition; // visionModeBipedPassBlock_block
	extern s_tag_block_definition visionModeBipedThreatBlock_block;
	extern s_tag_struct_definition visionModeBipedThreatBlock_block_struct_definition; // visionModeBipedThreatBlock_block
	extern s_tag_block_definition visionModeOrdnanceVehiclePassBlock_block;
	extern s_tag_struct_definition visionModeOrdnanceVehiclePassBlock_block_struct_definition; // visionModeOrdnanceVehiclePassBlock_block
	extern s_tag_block_definition visionModeOrdnanceVehicleTypeBlock_block;
	extern s_tag_struct_definition visionModeOrdnanceVehicleTypeBlock_block_struct_definition; // visionModeOrdnanceVehicleTypeBlock_block
	extern s_tag_block_definition visionModeOrdnanceCrosshairBlock_block;
	extern s_tag_struct_definition visionModeOrdnanceCrosshairBlock_block_struct_definition; // visionModeOrdnanceCrosshairBlock_block

	extern s_tag_struct_definition vision_mode_struct_definition; // tag group

	extern s_string_list_definition visionModeBipedTeamTypes;
	extern s_string_list_definition visionModeBipedPassFlags;
	extern s_string_list_definition visionModeBipedPassesFlags;
	extern s_string_list_definition visionModeFlags;




} // namespace blofeld

