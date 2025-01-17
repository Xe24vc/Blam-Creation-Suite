#pragma once

class c_graphics_d3d12;

class c_graphics_buffer_d3d12 :
	public c_graphics_buffer
{
public:
	c_graphics_buffer_d3d12() = delete;
	c_graphics_buffer_d3d12(const c_graphics_buffer_d3d12&) = delete;
	c_graphics_buffer_d3d12& operator=(const c_graphics_buffer_d3d12&) = delete;
	explicit c_graphics_buffer_d3d12(
		c_graphics_d3d12& graphics,
		e_graphics_buffer_type buffer_type,
		unsigned long element_size,
		unsigned long element_count,
		const wchar_t* name = nullptr);
	virtual ~c_graphics_buffer_d3d12();

	D3D12_GPU_DESCRIPTOR_HANDLE get_gpu_descriptor_handle() const;
	ID3D12Resource* get_resource() const;
	unsigned long get_data_size() const;
	virtual BCS_RESULT write_data(const void* buffer, unsigned long buffer_size) override;
	virtual BCS_RESULT read_data(void* buffer, unsigned long buffer_size) override;
	virtual void bind(unsigned long index) override;
	unsigned long get_gpu_descriptor_heap_index() const;

protected:
	void init_buffer(const wchar_t* name);
	void deinit_buffer();
	void init_descriptor_heap();
	void deinit_descriptor_heap();

public:
	c_graphics_d3d12& graphics;
	e_graphics_buffer_type buffer_type;

	ID3D12Resource* upload_heap; // #WARN: Can be same resource as gpu_resource
	ID3D12Resource* gpu_resource; // #WARN: Can be same resource as upload_heap

	D3D12_RESOURCE_STATES gpu_resource_state;
	D3D12_GPU_DESCRIPTOR_HANDLE gpu_descriptor_handle;

	unsigned long shader_visible_descriptor_heap_index;
	unsigned long element_size;
	unsigned long element_count;
	unsigned long data_size;
};

BCS_RESULT graphics_d3d12_buffer_create(
	c_graphics_d3d12* graphics,
	e_graphics_buffer_type buffer_type,
	unsigned long element_size,
	unsigned long element_count,
	c_graphics_buffer_d3d12*& buffer,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_buffer_create(
	c_graphics_d3d12* graphics,
	e_graphics_buffer_type buffer_type,
	unsigned long buffer_size,
	c_graphics_buffer_d3d12*& buffer,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_buffer_destroy(c_graphics_buffer_d3d12* buffer);
