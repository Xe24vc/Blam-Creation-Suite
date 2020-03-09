#pragma once

struct nicename("multiplayer_object_type_list") group('motl') s_multiplayer_object_type_list_definition
{
	enum nicename("Random Weapon Icon Index") e_random_weapon_icon_index : uint32_t
	{
		/*nicename("Dmr")*/ _random_weapon_icon_index_dmr = 1ui32,
		/*nicename("Assault Rifle")*/ _random_weapon_icon_index_assault_rifle = 2ui32,
		/*nicename("Plasma Pistol")*/ _random_weapon_icon_index_plasma_pistol = 3ui32,
		/*nicename("Spike Rifle")*/ _random_weapon_icon_index_spike_rifle = 4ui32,
		/*nicename("Smg")*/ _random_weapon_icon_index_smg = 5ui32,
		/*nicename("Energy Sword")*/ _random_weapon_icon_index_energy_sword = 6ui32,
		/*nicename("Magnum")*/ _random_weapon_icon_index_magnum = 7ui32,
		/*nicename("Needler")*/ _random_weapon_icon_index_needler = 8ui32,
		/*nicename("Plasma Rifle")*/ _random_weapon_icon_index_plasma_rifle = 9ui32,
		/*nicename("Rocket Launcher")*/ _random_weapon_icon_index_rocket_launcher = 10ui32,
		/*nicename("Shotgun")*/ _random_weapon_icon_index_shotgun = 11ui32,
		/*nicename("Sniper Rifle")*/ _random_weapon_icon_index_sniper_rifle = 12ui32,
		/*nicename("Grenade Launcher")*/ _random_weapon_icon_index_grenade_launcher = 13ui32,
		/*nicename("Focus Rifle")*/ _random_weapon_icon_index_focus_rifle = 14ui32,
		/*nicename("Spartan Laser")*/ _random_weapon_icon_index_spartan_laser = 15ui32,
		/*nicename("Gravity Hammer")*/ _random_weapon_icon_index_gravity_hammer = 16ui32,
		/*nicename("Mauler")*/ _random_weapon_icon_index_mauler = 17ui32,
		/*nicename("Flamethrower")*/ _random_weapon_icon_index_flamethrower = 18ui32,
		/*nicename("Golf Club Unused")*/ _random_weapon_icon_index_golf_club_unused = 19ui32,
		/*nicename("Plasma Repeater")*/ _random_weapon_icon_index_plasma_repeater = 20ui32,
		/*nicename("Needle Rifle")*/ _random_weapon_icon_index_needle_rifle = 21ui32,
		/*nicename("Focus Rifle Unused")*/ _random_weapon_icon_index_focus_rifle_unused = 22ui32,
		/*nicename("Plasma Launcher")*/ _random_weapon_icon_index_plasma_launcher = 23ui32,
		/*nicename("Concussion Rifle")*/ _random_weapon_icon_index_concussion_rifle = 24ui32,
		/*nicename("Grenade Launcher Unused")*/ _random_weapon_icon_index_grenade_launcher_unused = 25ui32,
		/*nicename("Golf Club")*/ _random_weapon_icon_index_golf_club = 26ui32,
		/*nicename("Fuel Rod Gun")*/ _random_weapon_icon_index_fuel_rod_gun = 27ui32,
		/*nicename("Question Mark")*/ _random_weapon_icon_index_question_mark = 28ui32,
	};

	enum nicename("Random Equipment Icon Index") e_random_equipment_icon_index : uint32_t
	{
		/*nicename("Armor Lock")*/ _random_equipment_icon_index_armor_lock = 1ui32,
		/*nicename("Active Camo")*/ _random_equipment_icon_index_active_camo = 2ui32,
		/*nicename("Sprint")*/ _random_equipment_icon_index_sprint = 3ui32,
		/*nicename("Jetpack")*/ _random_equipment_icon_index_jetpack = 4ui32,
		/*nicename("Evade")*/ _random_equipment_icon_index_evade = 5ui32,
		/*nicename("Hologram")*/ _random_equipment_icon_index_hologram = 6ui32,
		/*nicename("Empty Circle")*/ _random_equipment_icon_index_empty_circle = 7ui32,
		/*nicename("Drop Shield")*/ _random_equipment_icon_index_drop_shield = 8ui32,
		/*nicename("Vehicle")*/ _random_equipment_icon_index_vehicle = 9ui32,
	};

	struct nicename("Multiplayer Object List") s_multiplayer_object_list_definition
	{
		string_id nicename("Name") name;
		TagReference nicename("Object") object_reference;
	};

	struct nicename("Game Variant Weapons") s_game_variant_weapons_definition
	{
		enum nicename("Icon Index") e_icon_index : uint32_t
		{
			/*nicename("Dmr")*/ _icon_index_dmr = 1ui32,
			/*nicename("Assault Rifle")*/ _icon_index_assault_rifle = 2ui32,
			/*nicename("Plasma Pistol")*/ _icon_index_plasma_pistol = 3ui32,
			/*nicename("Spike Rifle")*/ _icon_index_spike_rifle = 4ui32,
			/*nicename("Smg")*/ _icon_index_smg = 5ui32,
			/*nicename("Energy Sword")*/ _icon_index_energy_sword = 6ui32,
			/*nicename("Magnum")*/ _icon_index_magnum = 7ui32,
			/*nicename("Needler")*/ _icon_index_needler = 8ui32,
			/*nicename("Plasma Rifle")*/ _icon_index_plasma_rifle = 9ui32,
			/*nicename("Rocket Launcher")*/ _icon_index_rocket_launcher = 10ui32,
			/*nicename("Shotgun")*/ _icon_index_shotgun = 11ui32,
			/*nicename("Sniper Rifle")*/ _icon_index_sniper_rifle = 12ui32,
			/*nicename("Grenade Launcher")*/ _icon_index_grenade_launcher = 13ui32,
			/*nicename("Focus Rifle")*/ _icon_index_focus_rifle = 14ui32,
			/*nicename("Spartan Laser")*/ _icon_index_spartan_laser = 15ui32,
			/*nicename("Gravity Hammer")*/ _icon_index_gravity_hammer = 16ui32,
			/*nicename("Mauler")*/ _icon_index_mauler = 17ui32,
			/*nicename("Flamethrower")*/ _icon_index_flamethrower = 18ui32,
			/*nicename("Golf Club Unused")*/ _icon_index_golf_club_unused = 19ui32,
			/*nicename("Plasma Repeater")*/ _icon_index_plasma_repeater = 20ui32,
			/*nicename("Needle Rifle")*/ _icon_index_needle_rifle = 21ui32,
			/*nicename("Focus Rifle Unused")*/ _icon_index_focus_rifle_unused = 22ui32,
			/*nicename("Plasma Launcher")*/ _icon_index_plasma_launcher = 23ui32,
			/*nicename("Concussion Rifle")*/ _icon_index_concussion_rifle = 24ui32,
			/*nicename("Grenade Launcher Unused")*/ _icon_index_grenade_launcher_unused = 25ui32,
			/*nicename("Golf Club")*/ _icon_index_golf_club = 26ui32,
			/*nicename("Fuel Rod Gun")*/ _icon_index_fuel_rod_gun = 27ui32,
			/*nicename("Question Mark")*/ _icon_index_question_mark = 28ui32,
		};

		int32_t nicename("Object Index") object_index;
		Undefined32 __unknown0;
		float nicename("Random Chance") random_chance;
		e_icon_index nicename("Icon Index") icon_index;
	};

	struct nicename("Game Variant Vehicles") s_game_variant_vehicles_definition
	{
		int32_t nicename("Object Index") object_index;
		Undefined32 __unknown0;
		float nicename("Random Chance") random_chance;
		int32_t nicename("Icon Index") icon_index;
	};

	struct nicename("Game Variant Grenades") s_game_variant_grenades_definition
	{
		enum nicename("Icon Index") e_icon_index : uint32_t
		{
			/*nicename("Plasma Grenade")*/ _icon_index_plasma_grenade = 1ui32,
			/*nicename("Frag Grenade")*/ _icon_index_frag_grenade = 2ui32,
		};

		int32_t nicename("Object Index") object_index;
		Undefined32 __unknown0;
		float nicename("Random Chance") random_chance;
		e_icon_index nicename("Icon Index") icon_index;
	};

	struct nicename("Game Variant Equipment") s_game_variant_equipment_definition
	{
		enum nicename("Icon Index") e_icon_index : uint32_t
		{
			/*nicename("Armor Lock")*/ _icon_index_armor_lock = 1ui32,
			/*nicename("Active Camo")*/ _icon_index_active_camo = 2ui32,
			/*nicename("Sprint")*/ _icon_index_sprint = 3ui32,
			/*nicename("Jetpack")*/ _icon_index_jetpack = 4ui32,
			/*nicename("Evade")*/ _icon_index_evade = 5ui32,
			/*nicename("Hologram")*/ _icon_index_hologram = 6ui32,
			/*nicename("Empty Circle")*/ _icon_index_empty_circle = 7ui32,
			/*nicename("Drop Shield")*/ _icon_index_drop_shield = 8ui32,
			/*nicename("Vehicle")*/ _icon_index_vehicle = 9ui32,
		};

		int32_t nicename("Object Index") object_index;
		Undefined32 __unknown0;
		float nicename("Random Chance") random_chance;
		e_icon_index nicename("Icon Index") icon_index;
	};

	struct nicename("Weapon Sets") s_weapon_sets_definition
	{
		struct nicename("Corrections") s_corrections_definition
		{
			int32_t nicename("Original Weapon Index") original_weapon_index;
			int32_t nicename("Replacement Weapon Index") replacement_weapon_index;
		};

		string_id nicename("Set Name") set_name;
		s_tag_block_definition<s_corrections_definition> nicename("Corrections") corrections_block;
	};

	struct nicename("Vehicle Sets") s_vehicle_sets_definition
	{
		struct nicename("Corrections") s_corrections1_definition
		{
			int32_t nicename("Original Vehicle Index") original_vehicle_index;
			int32_t nicename("Replacement Vehicle Index") replacement_vehicle_index;
		};

		string_id nicename("Set Name") set_name;
		s_tag_block_definition<s_corrections1_definition> nicename("Corrections") corrections_block;
	};

	s_tag_block_definition<s_multiplayer_object_list_definition> nicename("Multiplayer Object List") multiplayer_object_list_block;
	s_tag_block_definition<s_game_variant_weapons_definition> nicename("Game Variant Weapons") game_variant_weapons_block;
	s_tag_block_definition<s_game_variant_vehicles_definition> nicename("Game Variant Vehicles") game_variant_vehicles_block;
	s_tag_block_definition<s_game_variant_grenades_definition> nicename("Game Variant Grenades") game_variant_grenades_block;
	s_tag_block_definition<s_game_variant_equipment_definition> nicename("Game Variant Equipment") game_variant_equipment_block;
	s_tag_block_definition<s_weapon_sets_definition> nicename("Weapon Sets") weapon_sets_block;
	s_tag_block_definition<s_vehicle_sets_definition> nicename("Vehicle Sets") vehicle_sets_block;
	e_random_weapon_icon_index nicename("Random Weapon Icon Index") random_weapon_icon_index;
	e_random_equipment_icon_index nicename("Random Equipment Icon Index") random_equipment_icon_index;
};
