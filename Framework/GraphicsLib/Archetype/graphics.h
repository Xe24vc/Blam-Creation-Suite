#pragma once

enum e_graphics_architecture
{
	_graphics_architecture_null,
	_graphics_architecture_d3d11,
	_graphics_architecture_d3d12
};

class c_graphics
{
protected:
	c_graphics();
public:
	virtual ~c_graphics();

	virtual void render_frame() = 0;

	using t_present_callback_d3d12 = void();
	c_typed_callback<t_present_callback_d3d12> present_callback;

	using t_render_callback_d3d12 = void();
	c_typed_callback<t_render_callback_d3d12> render_callback;
};

BCS_DEBUG_API BCS_RESULT graphics_create(
	e_graphics_architecture architecture,
	bool use_debug_layer, 
	c_graphics*& graphics);
BCS_DEBUG_API BCS_RESULT graphics_destroy(c_graphics* graphics);
