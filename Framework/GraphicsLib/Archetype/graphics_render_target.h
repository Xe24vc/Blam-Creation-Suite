#pragma once

class c_graphics_swap_chain;

class c_graphics_render_target
{
protected:
	c_graphics_render_target();
public:
	virtual ~c_graphics_render_target();

	virtual BCS_RESULT resize(unsigned long width, unsigned long height) = 0;
	virtual BCS_RESULT clear_render_target() = 0;
	virtual BCS_RESULT get_ui_image_display_handle(void*& display_handle) = 0;

	using t_graphics_resize_callback = void(unsigned long width, unsigned long height);
	c_typed_callback<t_graphics_resize_callback> on_resize;
};

BCS_DEBUG_API BCS_RESULT graphics_swapchain_color_render_target_create(
	c_graphics* graphics,
	c_graphics_swap_chain* swap_chain,
	unsigned long swap_chain_buffer_index,
	float4 clear_color,
	c_graphics_render_target*& render_target,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_color_render_target_create(
	c_graphics* graphics,
	unsigned long width,
	unsigned long height,
	e_graphics_data_format format,
	float4 clear_color,
	c_graphics_render_target*& render_target,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_depth_stencil_render_target_create(
	c_graphics* graphics,
	unsigned long width,
	unsigned long height,
	e_graphics_data_format format,
	float clear_depth,
	unsigned char stencil_value,
	c_graphics_render_target*& render_target,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_render_target_destroy(c_graphics_render_target* render_target);
