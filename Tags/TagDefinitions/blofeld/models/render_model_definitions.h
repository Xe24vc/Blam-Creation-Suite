#pragma once

namespace blofeld
{



	constexpr unsigned long IMPOSTER_MODEL_TAG = 'impo';
	extern s_tag_group imposter_model_group; // imposter_model_block

	constexpr unsigned long RENDER_MODEL_TAG = 'mode';
	extern s_tag_group render_model_group; // render_model_block
	extern s_tag_block_definition render_model_block;
	extern s_tag_struct_definition render_model_block_struct_definition; // render_model_block

	constexpr unsigned long RENDER_MODEL_LIGHTMAP_ATLAS_TAG = 'rmla';
	extern s_tag_group render_model_lightmap_atlas_group; // render_model_lightmap_atlas_block

	//extern s_tag_struct_definition render_model_unknown_struct_unknown_block_struct_definition;
	extern s_tag_struct_definition render_model_unknown_sky_struct2_struct_definition;
	extern s_tag_struct_definition render_model_unknown_struct_struct_definition;

	extern s_tag_block_definition imposter_model_block;
	extern s_tag_block_definition render_model_lightmap_atlas_block;
	extern s_tag_block_definition imposter_mode_node_block;
	extern s_tag_struct_definition imposter_mode_node_block_struct_definition; // imposter_mode_node_block
	extern s_tag_block_definition render_model_region_block;
	extern s_tag_struct_definition render_model_region_block_struct_definition; // render_model_region_block
	extern s_tag_block_definition render_model_permutation_block;
	extern s_tag_struct_definition render_model_permutation_block_struct_definition; // render_model_permutation_block
	extern s_tag_block_definition render_model_node_block;
	extern s_tag_struct_definition render_model_node_block_struct_definition; // render_model_node_block
	extern s_tag_block_definition render_model_marker_group_block;
	extern s_tag_struct_definition render_model_marker_group_block_struct_definition; // render_model_marker_group_block
	extern s_tag_block_definition render_model_marker_block;
	extern s_tag_struct_definition render_model_marker_block_struct_definition; // render_model_marker_block
	extern s_tag_block_definition instance_node_map_mapping_block;
	extern s_tag_struct_definition instance_node_map_mapping_block_struct_definition; // instance_node_map_mapping_block
	extern s_tag_block_definition volume_samples_block;
	extern s_tag_struct_definition volume_samples_block_struct_definition; // volume_samples_block
	extern s_tag_block_definition default_node_orientations_block;
	extern s_tag_struct_definition default_node_orientations_block_struct_definition; // default_node_orientations_block
	extern s_tag_block_definition RenderModelBoneGroupBlock_block;
	extern s_tag_struct_definition RenderModelBoneGroupBlock_block_struct_definition; // RenderModelBoneGroupBlock_block
	extern s_tag_block_definition RenderModelNodeIndexBlock_block;
	extern s_tag_struct_definition RenderModelNodeIndexBlock_block_struct_definition; // RenderModelNodeIndexBlock_block

	extern s_tag_struct_definition radiance_transfer_matrix_array_struct_definition;
	extern s_tag_array_definition radiance_transfer_matrix_array;
	extern s_tag_struct_definition imposter_model_struct_definition; // tag group
	extern s_tag_struct_definition render_model_lightmap_atlas_struct_definition; // tag group

	extern s_string_list_definition procedure_enum_definition;
	extern s_string_list_definition procedure_axis_enum_definition;
	extern s_string_list_definition render_model_flags_definition;
	extern s_string_list_definition render_model_instance_bitfield_flags_definition;
	extern s_string_list_definition render_model_marker_flags_definition;

	extern s_tag_reference_definition RenderModelLightmapAtlasReference;



} // namespace blofeld

