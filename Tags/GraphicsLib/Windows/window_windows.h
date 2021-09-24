#pragma once

using on_window_procedure_callback = bool(void* userdata, HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam);

class c_window_windows :
	public c_window
{
public:
	c_window_windows() = delete;
	c_window_windows(const c_window_windows&) = delete;
	c_window_windows& operator=(const c_window_windows&) = delete;

	explicit c_window_windows(
		const char* window_title,
		const char* window_id,
		unsigned long width,
		unsigned long height,
		const char* debug_name);
	~c_window_windows();

	virtual bool update() override;

	static LRESULT CALLBACK window_procedure_callback(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam);
	LRESULT window_procedure(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam);

	using t_window_procedure_callback = void (HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam);
	c_typed_callback<t_window_procedure_callback> on_window_procedure;

	HWND window_handle;
	bool is_open;
};

BCS_RESULT window_windows_create(
	const char* window_title,
	const char* window_id,
	unsigned long width, 
	unsigned long height, 
	c_window_windows*& window,
	const char* debug_name);
BCS_RESULT window_windows_destroy(c_window_windows* window);
