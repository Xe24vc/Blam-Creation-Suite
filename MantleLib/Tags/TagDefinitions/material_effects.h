#pragma once

struct nicename("material_effects") tag_group('foot') s_material_effects_definition
{
	struct nicename("Effects") s_effects_definition
	{
		struct nicename("Old Materials") s_old_materials_definition
		{
			enum nicename("Sweetener Mode") e_sweetener_mode : uint8_t
			{
				/*nicename("Sweetener Default")*/ _sweetener_mode_sweetener_default = 1ui8,
				/*nicename("Sweetener Enabled")*/ _sweetener_mode_sweetener_enabled = 2ui8,
				/*nicename("Sweetener Disabled")*/ _sweetener_mode_sweetener_disabled = 3ui8,
			};

			TagReference nicename("Effect") effect_reference;
			TagReference nicename("Sound") sound_reference;
			string_id nicename("Material Name") material_name;
			int16_t nicename("Global Material Index") global_material_index;
			e_sweetener_mode nicename("Sweetener Mode") sweetener_mode;
			int8_t __unknown0;
			Undefined32 __unknown1;
		};

		struct nicename("Sounds") s_sounds_definition
		{
			enum nicename("Sweetener Mode") e_sweetener_mode : uint8_t
			{
				/*nicename("Sweetener Default")*/ _sweetener_mode_sweetener_default = 1ui8,
				/*nicename("Sweetener Enabled")*/ _sweetener_mode_sweetener_enabled = 2ui8,
				/*nicename("Sweetener Disabled")*/ _sweetener_mode_sweetener_disabled = 3ui8,
			};

			TagReference nicename("Tag") tag_reference;
			TagReference nicename("Secondary Tag") secondary_tag_reference;
			string_id nicename("Material Name") material_name;
			int16_t nicename("Global Material Index") global_material_index;
			e_sweetener_mode nicename("Sweetener Mode") sweetener_mode;
			int8_t __unknown0;
			Undefined32 __unknown1;
		};

		struct nicename("Effects") s_effects1_definition
		{
			enum nicename("Sweetener Mode") e_sweetener_mode : uint8_t
			{
				/*nicename("Sweetener Default")*/ _sweetener_mode_sweetener_default = 1ui8,
				/*nicename("Sweetener Enabled")*/ _sweetener_mode_sweetener_enabled = 2ui8,
				/*nicename("Sweetener Disabled")*/ _sweetener_mode_sweetener_disabled = 3ui8,
			};

			TagReference nicename("Tag") tag_reference;
			TagReference nicename("Secondary Tag") secondary_tag_reference;
			string_id nicename("Material Name") material_name;
			int16_t nicename("Global Material Index") global_material_index;
			e_sweetener_mode nicename("Sweetener Mode") sweetener_mode;
			int8_t __unknown0;
			Undefined32 __unknown1;
		};

		s_tag_block_definition<s_old_materials_definition> nicename("Old Materials") old_materials_block;
		s_tag_block_definition<s_sounds_definition> nicename("Sounds") sounds_block;
		s_tag_block_definition<s_effects1_definition> nicename("Effects") effects_block;
	};

	s_tag_block_definition<s_effects_definition> nicename("Effects") effects_block;
};

