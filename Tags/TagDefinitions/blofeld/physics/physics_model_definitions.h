#pragma once

namespace blofeld
{



	constexpr unsigned long PHYSICS_MODEL_TAG = 'phmo';
	extern s_tag_group physics_model_group; // physics_model_block


	extern s_tag_block_definition physics_model_block;
	extern s_tag_block_definition spheres_block;
	extern s_tag_struct_definition spheres_block_struct_definition; // spheres_block
	extern s_tag_block_definition materials_block;
	extern s_tag_struct_definition materials_block_struct_definition; // materials_block
	extern s_tag_block_definition phantom_types_block;
	extern s_tag_struct_definition phantom_types_block_struct_definition; // phantom_types_block
	extern s_tag_block_definition phantoms_block;
	extern s_tag_struct_definition phantoms_block_struct_definition; // phantoms_block
	extern s_tag_block_definition pills_block;
	extern s_tag_struct_definition pills_block_struct_definition; // pills_block
	extern s_tag_block_definition lists_block;
	extern s_tag_struct_definition lists_block_struct_definition; // lists_block
	extern s_tag_block_definition list_shapes_block;
	extern s_tag_struct_definition list_shapes_block_struct_definition; // list_shapes_block
	extern s_tag_block_definition physics_model_damped_spring_motor_block;
	extern s_tag_struct_definition physics_model_damped_spring_motor_block_struct_definition; // physics_model_damped_spring_motor_block
	extern s_tag_block_definition physics_model_position_motor_block;
	extern s_tag_struct_definition physics_model_position_motor_block_struct_definition; // physics_model_position_motor_block
	extern s_tag_block_definition physics_model_powered_chains_block;
	extern s_tag_struct_definition physics_model_powered_chains_block_struct_definition; // physics_model_powered_chains_block
	extern s_tag_block_definition physics_model_powered_chain_nodes_block;
	extern s_tag_struct_definition physics_model_powered_chain_nodes_block_struct_definition; // physics_model_powered_chain_nodes_block
	extern s_tag_block_definition nodes_block;
	extern s_tag_struct_definition nodes_block_struct_definition; // nodes_block
	extern s_tag_block_definition physics_model_powered_chain_constraints_block;
	extern s_tag_struct_definition physics_model_powered_chain_constraints_block_struct_definition; // physics_model_powered_chain_constraints_block
	extern s_tag_block_definition physics_model_node_constraint_edge_block;
	extern s_tag_struct_definition physics_model_node_constraint_edge_block_struct_definition; // physics_model_node_constraint_edge_block
	extern s_tag_block_definition physics_model_constraint_edge_constraint_block;
	extern s_tag_struct_definition physics_model_constraint_edge_constraint_block_struct_definition; // physics_model_constraint_edge_constraint_block
	extern s_tag_block_definition physics_model_ragdoll_motors_block;
	extern s_tag_struct_definition physics_model_ragdoll_motors_block_struct_definition; // physics_model_ragdoll_motors_block
	extern s_tag_block_definition physics_model_limited_hinge_motors_block;
	extern s_tag_struct_definition physics_model_limited_hinge_motors_block_struct_definition; // physics_model_limited_hinge_motors_block
	extern s_tag_block_definition rigid_bodies_block;
	extern s_tag_struct_definition rigid_bodies_block_struct_definition; // rigid_bodies_block
	extern s_tag_block_definition regions_block;
	extern s_tag_struct_definition regions_block_struct_definition; // regions_block
	extern s_tag_block_definition permutations_block;
	extern s_tag_struct_definition permutations_block_struct_definition; // permutations_block
	extern s_tag_block_definition rigid_body_indices_block;
	extern s_tag_struct_definition rigid_body_indices_block_struct_definition; // rigid_body_indices_block
	extern s_tag_block_definition RigidBodySerializedShapesBlock_block;
	extern s_tag_struct_definition RigidBodySerializedShapesBlock_block_struct_definition; // RigidBodySerializedShapesBlock_block
	extern s_tag_block_definition MoppSerializedHavokDataBlock_block;
	extern s_tag_struct_definition MoppSerializedHavokDataBlock_block_struct_definition; // MoppSerializedHavokDataBlock_block
	extern s_tag_block_definition multi_spheres_block;
	extern s_tag_struct_definition multi_spheres_block_struct_definition; // multi_spheres_block
	extern s_tag_block_definition boxes_block;
	extern s_tag_struct_definition boxes_block_struct_definition; // boxes_block
	extern s_tag_block_definition triangles_block;
	extern s_tag_struct_definition triangles_block_struct_definition; // triangles_block
	extern s_tag_block_definition polyhedra_block;
	extern s_tag_struct_definition polyhedra_block_struct_definition; // polyhedra_block
	extern s_tag_block_definition polyhedron_four_vectors_block;
	extern s_tag_struct_definition polyhedron_four_vectors_block_struct_definition; // polyhedron_four_vectors_block
	extern s_tag_block_definition polyhedron_plane_equations_block;
	extern s_tag_struct_definition polyhedron_plane_equations_block_struct_definition; // polyhedron_plane_equations_block
	extern s_tag_block_definition mass_distributions_block;
	extern s_tag_struct_definition mass_distributions_block_struct_definition; // mass_distributions_block
	extern s_tag_block_definition mopps_block;
	extern s_tag_struct_definition mopps_block_struct_definition; // mopps_block
	extern s_tag_block_definition hinge_constraints_block;
	extern s_tag_struct_definition hinge_constraints_block_struct_definition; // hinge_constraints_block
	extern s_tag_block_definition ragdoll_constraints_block;
	extern s_tag_struct_definition ragdoll_constraints_block_struct_definition; // ragdoll_constraints_block
	extern s_tag_block_definition point_to_path_curve_block;
	extern s_tag_struct_definition point_to_path_curve_block_struct_definition; // point_to_path_curve_block
	extern s_tag_block_definition point_to_path_curve_point_block;
	extern s_tag_struct_definition point_to_path_curve_point_block_struct_definition; // point_to_path_curve_point_block
	extern s_tag_block_definition limited_hinge_constraints_block;
	extern s_tag_struct_definition limited_hinge_constraints_block_struct_definition; // limited_hinge_constraints_block
	extern s_tag_block_definition ball_and_socket_constraints_block;
	extern s_tag_struct_definition ball_and_socket_constraints_block_struct_definition; // ball_and_socket_constraints_block
	extern s_tag_block_definition stiff_spring_constraints_block;
	extern s_tag_struct_definition stiff_spring_constraints_block_struct_definition; // stiff_spring_constraints_block
	extern s_tag_block_definition prismatic_constraints_block;
	extern s_tag_struct_definition prismatic_constraints_block_struct_definition; // prismatic_constraints_block

	extern s_tag_struct_definition multi_sphere_vector_storage_array_struct_definition;
	extern s_tag_array_definition multi_sphere_vector_storage_array;
	extern s_tag_struct_definition physics_model_struct_definition; // tag group
	extern s_tag_struct_definition havok_primitive_struct;
	extern s_tag_struct_definition havok_shape_struct;
	extern s_tag_struct_definition havok_shape_reference_struct;
	extern s_tag_struct_definition havok_convex_shape_struct;
	extern s_tag_struct_definition havok_convex_translate_shape_struct;
	extern s_tag_struct_definition havok_shape_collection_struct_2010_2;
	extern s_tag_struct_definition havok_shape_struct_2010_2;
	extern s_tag_struct_definition physics_model_motor_reference_struct;
	extern s_tag_struct_definition havok_convex_transform_shape_struct;
	extern s_tag_struct_definition havok_convex_shape_struct_2010_2;
	extern s_tag_struct_definition constraint_bodies_struct;

	extern s_string_list_definition physics_material_flags;
	extern s_string_list_definition PhantomFlagsV2;
	extern s_string_list_definition rigid_body_size_enum;
	extern s_string_list_definition physics_material_proxy_collision_groups;
	extern s_string_list_definition shape_enum;
	extern s_string_list_definition physics_model_flags;
	extern s_string_list_definition rigid_constraint_types_enum;
	extern s_string_list_definition physics_model_motor_types_enum;
	extern s_string_list_definition rigid_body_constraint_edge_constraint_flags_definition;
	extern s_string_list_definition nodes_flags;
	extern s_string_list_definition rigid_body_flags;
	extern s_string_list_definition rigid_body_motion_enum;
	extern s_string_list_definition rigid_body_collision_quality_enum;



} // namespace blofeld

