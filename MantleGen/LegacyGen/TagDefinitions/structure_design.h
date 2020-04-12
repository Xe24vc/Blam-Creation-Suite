#pragma once

struct nicename("structure_design") tag_group('sddt') s_structure_design_definition_legacy
{
	struct nicename("Design MOPP Codes") s_design_mopp_codes_definition_legacy
	{
		struct nicename("Data") s_data_definition_legacy
		{
			uint8_t nicename("Data Byte") data_byte;
		};

		int32_t __unknown0;
		s_undefined32_legacy __unknown1;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		int32_t nicename("Offset") offset;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		float nicename("Offset x") offset_x;
		float nicename("Offset y") offset_y;
		float nicename("Offset z") offset_z;
		float nicename("Offset Scale") offset_scale;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		int32_t nicename("Data Size") data_size;
		uint32_t nicename("Data Capacity") data_capacity;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_tag_block_legacy<s_data_definition_legacy> nicename("Data") data_block;
		s_undefined32_legacy __unknown12;
	};

	struct nicename("Design Shapes 2") s_design_shapes_2_definition_legacy
	{
		struct nicename("Unknown 2") s_unknown_2_definition_legacy
		{
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
			s_undefined32_legacy __unknown3;
			s_undefined32_legacy __unknown4;
			s_undefined32_legacy __unknown5;
			s_undefined32_legacy __unknown6;
			s_undefined32_legacy __unknown7;
			s_undefined32_legacy __unknown8;
			s_undefined32_legacy __unknown9;
			s_undefined32_legacy __unknown10;
			s_undefined32_legacy __unknown11;
			s_undefined32_legacy __unknown12;
			s_undefined32_legacy __unknown13;
			s_undefined32_legacy __unknown14;
			s_undefined32_legacy __unknown15;
			s_undefined32_legacy __unknown16;
		};

		string_id_legacy nicename("Name") name;
		int16_t __unknown0;
		int16_t __unknown1;
		s_tag_block_legacy<s_unknown_2_definition_legacy> nicename("Unknown 2") unknown_2_block;
	};

	struct nicename("Water MOPP Codes") s_water_mopp_codes_definition_legacy
	{
		struct nicename("Data") s_data1_definition_legacy
		{
			uint8_t nicename("Data Byte") data_byte;
		};

		int32_t __unknown0;
		s_undefined32_legacy __unknown1;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		int32_t nicename("Offset") offset;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		float nicename("Offset x") offset_x;
		float nicename("Offset y") offset_y;
		float nicename("Offset z") offset_z;
		float nicename("Offset Scale") offset_scale;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		int32_t nicename("Data Size") data_size;
		uint32_t nicename("Data Capacity") data_capacity;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_tag_block_legacy<s_data1_definition_legacy> nicename("Data") data_block;
		s_undefined32_legacy __unknown12;
	};

	struct nicename("Water Names") s_water_names_definition_legacy
	{
		string_id_legacy nicename("Name") name;
	};

	struct nicename("Underwater Definitions") s_underwater_definitions_definition_legacy
	{
		struct nicename("Unknown") s_unknown_definition_legacy
		{
			float __unknown0;
			float __unknown1;
			float __unknown2;
			float __unknown3;
		};

		int16_t nicename("Water Name Index") water_name_index;
		int16_t __unknown0;
		float nicename("Flow Force x") flow_force_x;
		float nicename("Flow Force y") flow_force_y;
		float nicename("Flow Force z") flow_force_z;
		float nicename("Flow Force z 2") flow_force_z_2;
		s_colorf_legacy nicename("Mask Color") mask_color;
		float nicename("Obscure Amount") obscure_amount;
		s_tag_block_legacy<s_unknown_definition_legacy> __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy nicename("X Min") x_min;
		s_undefined32_legacy nicename("X Max") x_max;
		s_undefined32_legacy nicename("Y Min") y_min;
		s_undefined32_legacy nicename("Y Max") y_max;
		s_undefined32_legacy nicename("Z Min") z_min;
		s_undefined32_legacy nicename("Z Max") z_max;
	};

	struct nicename("Planar Fog") s_planar_fog_definition_legacy
	{
		struct nicename("Unknown") s_unknown1_definition_legacy
		{
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
		};

		struct nicename("Unknown") s_unknown2_definition_legacy
		{
			struct nicename("Unknown") s_unknown3_definition_legacy
			{
				s_undefined32_legacy __unknown0;
				s_undefined32_legacy __unknown1;
				s_undefined32_legacy __unknown2;
				s_undefined32_legacy __unknown3;
			};

			s_tag_block_legacy<s_unknown3_definition_legacy> __unknown0;
		};

		string_id_legacy nicename("Name") name;
		s_tag_reference_legacy nicename("Planar Fog Parameters") planar_fog_parameters_reference;
		s_tag_block_legacy<s_unknown1_definition_legacy> __unknown0;
		s_tag_block_legacy<s_unknown2_definition_legacy> __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
	};

	struct nicename("Unknown MOPP Codes") s_unknown_mopp_codes_definition_legacy
	{
		struct nicename("Data") s_data2_definition_legacy
		{
			uint8_t nicename("Data Byte") data_byte;
		};

		int32_t __unknown0;
		s_undefined32_legacy __unknown1;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		int32_t nicename("Offset") offset;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		float nicename("Offset x") offset_x;
		float nicename("Offset y") offset_y;
		float nicename("Offset z") offset_z;
		float nicename("Offset Scale") offset_scale;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		int32_t nicename("Data Size") data_size;
		uint32_t nicename("Data Capacity") data_capacity;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_tag_block_legacy<s_data2_definition_legacy> nicename("Data") data_block;
		s_undefined32_legacy __unknown12;
	};

	struct nicename("Meshes") s_meshes_definition_legacy
	{
		enum nicename("Vertex Type") e_vertex_type : uint8_t
		{
			/*nicename("World")*/ _vertex_type_world = 0ui8,
			/*nicename("Rigid")*/ _vertex_type_rigid = 1ui8,
			/*nicename("Skinned")*/ _vertex_type_skinned = 2ui8,
			/*nicename("Particle Model")*/ _vertex_type_particle_model = 3ui8,
			/*nicename("Flat World")*/ _vertex_type_flat_world = 4ui8,
			/*nicename("Flat Rigid")*/ _vertex_type_flat_rigid = 5ui8,
			/*nicename("Flat Skinned")*/ _vertex_type_flat_skinned = 6ui8,
			/*nicename("Screen")*/ _vertex_type_screen = 7ui8,
			/*nicename("Debug")*/ _vertex_type_debug = 8ui8,
			/*nicename("Transparent")*/ _vertex_type_transparent = 9ui8,
			/*nicename("Particle")*/ _vertex_type_particle = 10ui8,
			/*nicename("Contrail")*/ _vertex_type_contrail = 11ui8,
			/*nicename("Light Volume")*/ _vertex_type_light_volume = 12ui8,
			/*nicename("Chud Simple")*/ _vertex_type_chud_simple = 13ui8,
			/*nicename("Chud Fancy")*/ _vertex_type_chud_fancy = 14ui8,
			/*nicename("Decorator")*/ _vertex_type_decorator = 15ui8,
			/*nicename("Tiny Position")*/ _vertex_type_tiny_position = 16ui8,
			/*nicename("Patchy Fog")*/ _vertex_type_patchy_fog = 17ui8,
			/*nicename("Water")*/ _vertex_type_water = 18ui8,
			/*nicename("Ripple")*/ _vertex_type_ripple = 19ui8,
			/*nicename("Implicit")*/ _vertex_type_implicit = 20ui8,
			/*nicename("Beam")*/ _vertex_type_beam = 21ui8,
			/*nicename("World Tessellated")*/ _vertex_type_world_tessellated = 22ui8,
			/*nicename("Rigid Tessellated")*/ _vertex_type_rigid_tessellated = 23ui8,
			/*nicename("Skinned Tessellated")*/ _vertex_type_skinned_tessellated = 24ui8,
			/*nicename("Shader Cache")*/ _vertex_type_shader_cache = 25ui8,
			/*nicename("Structure Instance Imposter")*/ _vertex_type_structure_instance_imposter = 26ui8,
			/*nicename("Object Imposter")*/ _vertex_type_object_imposter = 27ui8,
			/*nicename("Rigid Compressed")*/ _vertex_type_rigid_compressed = 28ui8,
			/*nicename("Skinned Compressed")*/ _vertex_type_skinned_compressed = 29ui8,
			/*nicename("Light Volume Precompiled")*/ _vertex_type_light_volume_precompiled = 30ui8,
		};

		enum nicename("PRT Type") e_prt_type : uint8_t
		{
			/*nicename("None")*/ _prt_type_none = 0ui8,
			/*nicename("Ambient")*/ _prt_type_ambient = 1ui8,
			/*nicename("Linear")*/ _prt_type_linear = 2ui8,
			/*nicename("Quadratic")*/ _prt_type_quadratic = 3ui8,
		};

		enum nicename("Index Buffer Type") e_index_buffer_type : uint8_t
		{
			/*nicename("Point List")*/ _index_buffer_type_point_list = 0ui8,
			/*nicename("Line List")*/ _index_buffer_type_line_list = 1ui8,
			/*nicename("Line Strip")*/ _index_buffer_type_line_strip = 2ui8,
			/*nicename("Triange List")*/ _index_buffer_type_triange_list = 3ui8,
			/*nicename("Triange Fan")*/ _index_buffer_type_triange_fan = 4ui8,
			/*nicename("Triange Strip")*/ _index_buffer_type_triange_strip = 5ui8,
		};

		enum nicename("Flags") b_flags : uint16_t /* bitfield */
		{
			/*nicename("Has Vertex Colors")*/ _flags_has_vertex_colors = 1ui16 << 0ui16,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
		};

		struct nicename("Parts") s_parts_definition_legacy
		{
			int16_t nicename("Material Index") material_index;
			int16_t nicename("'Unknown Nodey' Index") unknown_nodey_index;
			int32_t nicename("Index Buffer Start") index_buffer_start;
			int32_t nicename("Index Buffer Count") index_buffer_count;
			int16_t nicename("Subpart Start") subpart_start;
			int16_t nicename("Subpart Count") subpart_count;
			int8_t nicename("Unknown Enum?") unknown_enum;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int16_t nicename("Vertex Count") vertex_count;
			int16_t __unknown3;
		};

		struct nicename("Subparts") s_subparts_definition_legacy
		{
			int32_t nicename("Index Buffer Start") index_buffer_start;
			int32_t nicename("Index Buffer Count") index_buffer_count;
			int16_t nicename("Part Index") part_index;
			int16_t nicename("Vertex Count") vertex_count;
			int32_t __unknown0;
		};

		struct nicename("Instanced Geometry Indices") s_instanced_geometry_indices_definition_legacy
		{
			struct nicename("Instanced Geometry Mesh Contents") s_instanced_geometry_mesh_contents_definition_legacy
			{
				int16_t nicename("Instanced Geometry Index") instanced_geometry_index;
			};

			int16_t nicename("Instanced Geometry Mesh Index 1") instanced_geometry_mesh_index_1;
			int16_t nicename("Instanced Geometry Mesh Index 2") instanced_geometry_mesh_index_2;
			s_tag_block_legacy<s_instanced_geometry_mesh_contents_definition_legacy> nicename("Instanced Geometry Mesh Contents") instanced_geometry_mesh_contents_block;
		};

		struct nicename("Unknown Water") s_unknown_water_definition_legacy
		{
			int16_t __unknown0;
		};

		s_tag_block_legacy<s_parts_definition_legacy> nicename("Parts") parts_block;
		s_tag_block_legacy<s_subparts_definition_legacy> nicename("Subparts") subparts_block;
		int16_t nicename("Vertex Buffer Index 1") vertex_buffer_index_1;
		int16_t nicename("Vertex Buffer Index 2") vertex_buffer_index_2;
		int16_t nicename("Vertex Buffer Index 3") vertex_buffer_index_3;
		int16_t nicename("Vertex Buffer Index 4") vertex_buffer_index_4;
		int16_t nicename("Vertex Buffer Index 5") vertex_buffer_index_5;
		int16_t nicename("Vertex Buffer Index 6") vertex_buffer_index_6;
		int16_t nicename("Vertex Buffer Index 7") vertex_buffer_index_7;
		int16_t nicename("Vertex Buffer Index 8") vertex_buffer_index_8;
		int16_t nicename("Index Buffer Index 1") index_buffer_index_1;
		int16_t nicename("Index Buffer Index 2") index_buffer_index_2;
		b_flags nicename("Flags") flags;
		int8_t nicename("Rigid Node") rigid_node;
		e_vertex_type nicename("Vertex Type") vertex_type;
		e_prt_type nicename("PRT Type") prt_type;
		int8_t __unknown0;
		e_index_buffer_type nicename("Index Buffer Type") index_buffer_type;
		int8_t __unknown1;
		s_tag_block_legacy<s_instanced_geometry_indices_definition_legacy> nicename("Instanced Geometry Indices") instanced_geometry_indices_block;
		s_tag_block_legacy<s_unknown_water_definition_legacy> nicename("Unknown Water") unknown_water_block;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
	};

	struct nicename("Compression Info") s_compression_info_definition_legacy
	{
		int16_t __unknown0;
		int16_t __unknown1;
		float nicename("Position Bounds X min") position_bounds_x_min;
		float nicename("Position Bounds X max") position_bounds_x_max;
		float nicename("Position Bounds Y min") position_bounds_y_min;
		float nicename("Position Bounds Y max") position_bounds_y_max;
		float nicename("Position Bounds Z min") position_bounds_z_min;
		float nicename("Position Bounds Z max") position_bounds_z_max;
		float nicename("Texcoord Bounds X min") texcoord_bounds_x_min;
		float nicename("Texcoord Bounds X max") texcoord_bounds_x_max;
		float nicename("Texcoord Bounds Y min") texcoord_bounds_y_min;
		float nicename("Texcoord Bounds Y max") texcoord_bounds_y_max;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
	};

	struct nicename("Unknown Nodey") s_unknown_nodey_definition_legacy
	{
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		int8_t nicename("Node Index") node_index;
		int8_t nicename("Node Index") node_index1;
		int8_t nicename("Node Index") node_index2;
		int8_t nicename("Node Index") node_index3;
		float __unknown8;
		float __unknown9;
		float __unknown10;
	};

	struct nicename("Unknown 8") s_unknown_8_definition_legacy
	{
		int16_t __unknown0;
		int16_t __unknown1;
		s_data_reference_legacy __unknown2;
	};

	struct nicename("Node Maps") s_node_maps_definition_legacy
	{
		struct nicename("Unknown") s_unknown4_definition_legacy
		{
			uint8_t nicename("Node Index") node_index;
		};

		s_tag_block_legacy<s_unknown4_definition_legacy> __unknown0;
	};

	struct nicename("Unknown Yo") s_unknown_yo_definition_legacy
	{
		int16_t nicename("Unknown Index") unknown_index;
	};

	struct nicename("Water Meshes") s_water_meshes_definition_legacy
	{
		int16_t nicename("Mesh Index") mesh_index;
		int16_t __unknown0;
		float nicename("X Min") x_min;
		float nicename("X Max") x_max;
		float nicename("Y Min") y_min;
		float nicename("Y Max") y_max;
		float nicename("Z Min") z_min;
		float nicename("Z Max") z_max;
	};

	struct nicename("Unknown Compression Info") s_unknown_compression_info_definition_legacy
	{
		uint32_t nicename("Polyart Asset Address") polyart_asset_address;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
	};

	struct nicename("Unknown 7") s_unknown_7_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_undefined32_legacy __unknown21;
		s_undefined32_legacy __unknown22;
		s_undefined32_legacy __unknown23;
		s_undefined32_legacy __unknown24;
		s_undefined32_legacy __unknown25;
		s_undefined32_legacy __unknown26;
		s_undefined32_legacy __unknown27;
		s_undefined32_legacy __unknown28;
		s_undefined32_legacy __unknown29;
		s_undefined32_legacy __unknown30;
		s_undefined32_legacy __unknown31;
		s_undefined32_legacy __unknown32;
		s_undefined32_legacy __unknown33;
		s_undefined32_legacy __unknown34;
		s_undefined32_legacy __unknown35;
		s_undefined32_legacy __unknown36;
		s_undefined32_legacy __unknown37;
		s_undefined32_legacy __unknown38;
		s_undefined32_legacy __unknown39;
		s_undefined32_legacy __unknown40;
		s_undefined32_legacy __unknown41;
		s_undefined32_legacy __unknown42;
		s_undefined32_legacy __unknown43;
		s_undefined32_legacy __unknown44;
		s_undefined32_legacy __unknown45;
		s_undefined32_legacy __unknown46;
		s_undefined32_legacy __unknown47;
		s_undefined32_legacy __unknown48;
		s_undefined32_legacy __unknown49;
		s_undefined32_legacy __unknown50;
		s_undefined32_legacy __unknown51;
		s_undefined32_legacy __unknown52;
		s_undefined32_legacy __unknown53;
		s_undefined32_legacy __unknown54;
		s_undefined32_legacy __unknown55;
		s_undefined32_legacy __unknown56;
		s_undefined32_legacy __unknown57;
		s_undefined32_legacy __unknown58;
		s_undefined32_legacy __unknown59;
		s_undefined32_legacy __unknown60;
		s_undefined32_legacy __unknown61;
		s_undefined32_legacy __unknown62;
		s_undefined32_legacy __unknown63;
		s_undefined32_legacy __unknown64;
		s_undefined32_legacy __unknown65;
		s_undefined32_legacy __unknown66;
		s_undefined32_legacy __unknown67;
		s_undefined32_legacy __unknown68;
		s_undefined32_legacy __unknown69;
		s_undefined32_legacy __unknown70;
		s_undefined32_legacy __unknown71;
		s_undefined32_legacy __unknown72;
		s_undefined32_legacy __unknown73;
		s_undefined32_legacy __unknown74;
		s_undefined32_legacy __unknown75;
		s_undefined32_legacy __unknown76;
		s_undefined32_legacy __unknown77;
		s_undefined32_legacy __unknown78;
		s_undefined32_legacy __unknown79;
		int16_t __unknown80;
		int16_t __unknown81;
	};

	struct nicename("Instanced Geometry Instances") s_instanced_geometry_instances_definition_legacy
	{
		enum nicename("Flags") b_flags : uint16_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags_bit_0 = 1ui16 << 0ui16,
			/*nicename("No Projectile Collision")*/ _flags_no_projectile_collision = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
		};

		float nicename("Scale") scale;
		float nicename("Forward i") forward_i;
		float nicename("Forward j") forward_j;
		float nicename("Forward k") forward_k;
		float nicename("Left i") left_i;
		float nicename("Left j") left_j;
		float nicename("Left k") left_k;
		float nicename("Up i") up_i;
		float nicename("Up j") up_j;
		float nicename("Up k") up_k;
		float nicename("Position x") position_x;
		float nicename("Position y") position_y;
		float nicename("Position z") position_z;
		int16_t nicename("Mesh Index") mesh_index;
		b_flags nicename("Flags") flags;
		int16_t __unknown0;
		int16_t __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		float nicename("Bounding Sphere x") bounding_sphere_x;
		float nicename("Bounding Sphere y") bounding_sphere_y;
		float nicename("Bounding Sphere z") bounding_sphere_z;
		float nicename("Bounding Sphere Radius1") bounding_sphere_radius1;
		float __unknown12;
		float nicename("Bounding Sphere Radius2") bounding_sphere_radius2;
		int8_t __unknown13;
		int8_t __unknown14;
		int8_t __unknown15;
		int8_t __unknown16;
		float __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_undefined32_legacy __unknown21;
		s_undefined32_legacy __unknown22;
		s_undefined32_legacy __unknown23;
		string_id_legacy nicename("Name") name;
	};

	struct nicename("Materials") s_materials_definition_legacy
	{
		s_tag_reference_legacy nicename("Shader") shader_reference;
		int32_t __unknown0;
		float __unknown1;
		s_undefined32_legacy __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
		int8_t __unknown5;
		int8_t __unknown6;
		float __unknown7;
		float __unknown8;
		int8_t __unknown9;
		int8_t nicename("Breakable Surface Index") breakable_surface_index;
		int8_t __unknown10;
		int8_t __unknown11;
	};

	s_undefined32_legacy __unknown0;
	s_undefined32_legacy __unknown1;
	s_undefined32_legacy __unknown2;
	s_undefined32_legacy __unknown3;
	int32_t __unknown4;
	int32_t __unknown5;
	s_undefined32_legacy __unknown6;
	s_undefined32_legacy __unknown7;
	s_undefined32_legacy __unknown8;
	s_undefined32_legacy __unknown9;
	s_undefined32_legacy __unknown10;
	s_undefined32_legacy __unknown11;
	int32_t __unknown12;
	s_tag_block_legacy<s_design_mopp_codes_definition_legacy> nicename("Design MOPP Codes") design_mopp_codes_block;
	s_tag_block_legacy<s_design_shapes_2_definition_legacy> nicename("Design Shapes 2") design_shapes_2_block;
	s_tag_block_legacy<s_water_mopp_codes_definition_legacy> nicename("Water MOPP Codes") water_mopp_codes_block;
	s_tag_block_legacy<s_water_names_definition_legacy> nicename("Water Names") water_names_block;
	s_tag_block_legacy<s_underwater_definitions_definition_legacy> nicename("Underwater Definitions") underwater_definitions_block;
	s_tag_block_legacy<s_planar_fog_definition_legacy> nicename("Planar Fog") planar_fog_block;
	s_tag_block_legacy<s_unknown_mopp_codes_definition_legacy> nicename("Unknown MOPP Codes") unknown_mopp_codes_block;
	int32_t __unknown13;
	s_tag_block_legacy<s_meshes_definition_legacy> nicename("Meshes") meshes_block;
	s_tag_block_legacy<s_compression_info_definition_legacy> nicename("Compression Info") compression_info_block;
	s_tag_block_legacy<s_unknown_nodey_definition_legacy> nicename("Unknown Nodey") unknown_nodey_block;
	s_tag_block_legacy<s_unknown_8_definition_legacy> nicename("Unknown 8") unknown_8_block;
	s_undefined32_legacy __unknown14;
	s_undefined32_legacy __unknown15;
	s_undefined32_legacy __unknown16;
	s_undefined32_legacy __unknown17;
	s_undefined32_legacy __unknown18;
	s_undefined32_legacy __unknown19;
	s_tag_block_legacy<s_node_maps_definition_legacy> nicename("Node Maps") node_maps_block;
	s_undefined32_legacy __unknown20;
	s_undefined32_legacy __unknown21;
	s_undefined32_legacy __unknown22;
	s_undefined32_legacy __unknown23;
	s_undefined32_legacy __unknown24;
	s_undefined32_legacy __unknown25;
	s_undefined32_legacy __unknown26;
	s_undefined32_legacy __unknown27;
	s_undefined32_legacy __unknown28;
	s_tag_block_legacy<s_unknown_yo_definition_legacy> nicename("Unknown Yo") unknown_yo_block;
	s_tag_block_legacy<s_water_meshes_definition_legacy> nicename("Water Meshes") water_meshes_block;
	int32_t nicename("[zone] Asset Datum") zone_asset_datum;
	uint16_t nicename("[easy read] Index") easy_read_index;
	uint16_t nicename("[easy read] Salt") easy_read_salt;
	int32_t nicename("Useless Padding") useless_padding;
	s_tag_block_legacy<s_unknown_compression_info_definition_legacy> nicename("Unknown Compression Info") unknown_compression_info_block;
	s_tag_block_legacy<s_unknown_7_definition_legacy> nicename("Unknown 7") unknown_7_block;
	s_tag_block_legacy<s_instanced_geometry_instances_definition_legacy> nicename("Instanced Geometry Instances") instanced_geometry_instances_block;
	s_tag_block_legacy<s_materials_definition_legacy> nicename("Materials") materials_block;
	s_undefined32_legacy __unknown29;
	s_undefined32_legacy __unknown30;
	s_undefined32_legacy __unknown31;
};
