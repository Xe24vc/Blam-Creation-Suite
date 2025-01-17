#pragma once

class c_graphics_d3d12;
class c_graphics_shader_binary_d3d12;
class c_graphics_vertex_layout_d3d12;
class c_graphics_vertex_layout_d3d12;

class c_graphics_shader_pipeline_d3d12 :
	public c_graphics_shader_pipeline
{
public:
	c_graphics_shader_pipeline_d3d12(
		c_graphics_d3d12& graphics,
		c_graphics_shader_binary_d3d12** shader_binaries,
		unsigned long num_shader_binaries,
		e_graphics_data_format* render_target_data_formats,
		unsigned long num_render_targets,
		e_graphics_data_format* depth_data_format,
		c_graphics_vertex_layout_d3d12& vertex_layout,
		const wchar_t* debug_name);
	virtual ~c_graphics_shader_pipeline_d3d12();

	virtual void bind() override;

	c_graphics_d3d12& graphics;
	ID3D12PipelineState* pipeline_state;
	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipeline_state_description;
};

BCS_RESULT graphics_d3d12_shader_pipeline_create(
	c_graphics_d3d12* graphics,
	c_graphics_shader_binary_d3d12** shader_binaries,
	unsigned long num_shader_binaries,
	e_graphics_data_format* render_target_data_formats,
	unsigned long num_render_targets,
	e_graphics_data_format* depth_data_format,
	c_graphics_vertex_layout_d3d12* vertex_layout,
	c_graphics_shader_pipeline_d3d12*& shader_pipeline,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_shader_pipeline_destroy(c_graphics_shader_pipeline_d3d12* shader_pipeline);
