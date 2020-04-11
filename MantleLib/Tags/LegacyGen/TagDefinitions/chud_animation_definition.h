#pragma once

struct nicename("chud_animation_definition") tag_group('chad') s_chud_animation_definition_definition_legacy
{
	enum nicename("Flags") b_flags : uint8_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _flags_bit_0 = 1ui8 << 0ui8,
		/*nicename("Loops")*/ _flags_loops = 1ui8 << 1ui8,
		/*nicename("Bit 2")*/ _flags_bit_2 = 1ui8 << 2ui8,
		/*nicename("Bit 3")*/ _flags_bit_3 = 1ui8 << 3ui8,
		/*nicename("Bit 4")*/ _flags_bit_4 = 1ui8 << 4ui8,
		/*nicename("Bit 5")*/ _flags_bit_5 = 1ui8 << 5ui8,
		/*nicename("Bit 6")*/ _flags_bit_6 = 1ui8 << 6ui8,
		/*nicename("Bit 7")*/ _flags_bit_7 = 1ui8 << 7ui8,
	};

	struct nicename("Position") s_position_definition_legacy
	{
		struct nicename("Animation") s_animation_definition_legacy
		{
			float nicename("Frame Number") frame_number;
			float nicename("Position X") position_x;
			float nicename("Position Y") position_y;
			float nicename("Position Z") position_z;
		};

		s_tag_block_legacy<s_animation_definition_legacy> nicename("Animation") animation_block;
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	struct nicename("Rotation") s_rotation_definition_legacy
	{
		struct nicename("Animation") s_animation1_definition_legacy
		{
			float nicename("Frame Number") frame_number;
			float nicename("X Angle") x_angle;
			float nicename("Y Angle") y_angle;
			float nicename("Z Angle") z_angle;
		};

		s_tag_block_legacy<s_animation1_definition_legacy> nicename("Animation") animation_block;
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	struct nicename("Size") s_size_definition_legacy
	{
		struct nicename("Animation") s_animation2_definition_legacy
		{
			float nicename("Frame Number") frame_number;
			float nicename("Stretch X") stretch_x;
			float nicename("Stretch Y") stretch_y;
		};

		s_tag_block_legacy<s_animation2_definition_legacy> nicename("Animation") animation_block;
		s_data_reference_legacy __unknown0;
	};

	struct nicename("Color") s_color_definition_legacy
	{
		struct nicename("Animation") s_animation3_definition_legacy
		{
			float nicename("Frame Number") frame_number;
		};

		s_tag_block_legacy<s_animation3_definition_legacy> nicename("Animation") animation_block;
		/* Color Function : Color 1 - x05 (11th character)
		   Color 2 - x09 (19th character)
		   Color 3 - x13 (27th character)
		   Color 4 - x17 (35th character)
		   If a tag uses 2 colors, x05 and x17. If 3 colors x05, x09, and x17. */
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	struct nicename("Alpha") s_alpha_definition_legacy
	{
		struct nicename("Animation") s_animation4_definition_legacy
		{
			float nicename("Frame Number") frame_number;
			float nicename("Alpha") alpha;
		};

		s_tag_block_legacy<s_animation4_definition_legacy> nicename("Animation") animation_block;
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	struct nicename("Alpha Unknown") s_alpha_unknown_definition_legacy
	{
		struct nicename("Animation") s_animation5_definition_legacy
		{
			float nicename("Frame Number") frame_number;
			float nicename("Alpha") alpha;
		};

		s_tag_block_legacy<s_animation5_definition_legacy> nicename("Animation") animation_block;
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	struct nicename("Bitmap") s_bitmap_definition_legacy
	{
		struct nicename("Animation") s_animation6_definition_legacy
		{
			float nicename("Frame Number") frame_number;
			float nicename("Movement 1 X") movement_1_x;
			float nicename("Movement 1 Y") movement_1_y;
			float nicename("Movement 2 X") movement_2_x;
			float nicename("Movement 2 Y") movement_2_y;
		};

		s_tag_block_legacy<s_animation6_definition_legacy> nicename("Animation") animation_block;
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	struct nicename("Ammo Counter Boot") s_ammo_counter_boot_definition_legacy
	{
		struct nicename("Ammo Counter") s_ammo_counter_definition_legacy
		{
			float nicename("Frame Number") frame_number;
			float nicename("Boot Progress Fraction") boot_progress_fraction;
		};

		s_tag_block_legacy<s_ammo_counter_definition_legacy> nicename("Ammo Counter") ammo_counter_block;
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	b_flags nicename("Flags") flags;
	int8_t __unknown0;
	int16_t __unknown1;
	s_tag_block_legacy<s_position_definition_legacy> nicename("Position") position_block;
	s_tag_block_legacy<s_rotation_definition_legacy> nicename("Rotation") rotation_block;
	s_tag_block_legacy<s_size_definition_legacy> nicename("Size") size_block;
	s_tag_block_legacy<s_color_definition_legacy> nicename("Color") color_block;
	s_tag_block_legacy<s_alpha_definition_legacy> nicename("Alpha") alpha_block;
	s_tag_block_legacy<s_alpha_unknown_definition_legacy> nicename("Alpha Unknown") alpha_unknown_block;
	s_tag_block_legacy<s_bitmap_definition_legacy> nicename("Bitmap") bitmap_block;
	s_tag_block_legacy<s_ammo_counter_boot_definition_legacy> nicename("Ammo Counter Boot") ammo_counter_boot_block;
	int32_t nicename("Unknown Animation Block") unknown_animation_block;
	int32_t nicename("Unknown Animation Block") unknown_animation_block1;
	int32_t nicename("Unknown Animation Block") unknown_animation_block2;
	float nicename("Number of Frames") number_of_frames;
};
