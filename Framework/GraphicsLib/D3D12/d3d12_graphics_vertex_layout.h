#pragma once

class c_graphics;

extern BCS_RESULT graphics_vertex_layout_stepping_to_d3d12_input_classification(e_graphics_vertex_layout_stepping stepping, D3D12_INPUT_CLASSIFICATION& input_classification);

class c_graphics_vertex_layout_d3d12 :
	public c_graphics_vertex_layout
{
public:
	c_graphics_vertex_layout_d3d12() = delete;
	c_graphics_vertex_layout_d3d12(const c_graphics_vertex_layout_d3d12&) = delete;
	c_graphics_vertex_layout_d3d12& operator=(const c_graphics_vertex_layout_d3d12&) = delete;
	explicit c_graphics_vertex_layout_d3d12(
		c_graphics_d3d12& graphics,
		s_graphics_vertex_layout_description* descriptions,
		unsigned long num_descriptions,
		const wchar_t* name = nullptr);
	virtual ~c_graphics_vertex_layout_d3d12();

	c_graphics_d3d12& graphics;
	D3D12_INPUT_ELEMENT_DESC* vertex_layout_descriptions;
	unsigned long num_layout_descriptions;


};

BCS_RESULT graphics_d3d12_vertex_layout_create(
	c_graphics_d3d12* graphics,
	s_graphics_vertex_layout_description* descriptions,
	unsigned long num_layout_descriptions,
	c_graphics_vertex_layout_d3d12*& vertex_layout,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_vertex_layout_destroy(c_graphics_vertex_layout_d3d12* vertex_layout);
