#include "mandrill-private-pch.h"

#ifdef _DEBUG
static constexpr const char window_title[] = "Mandrill Debug";
#else
static constexpr const char window_title[] = "Mandrill";
#endif

static c_window* window;
static c_render_context* window_render_context;
static c_mandrill_user_interface* mandrill_user_interface;

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(wWinMain));
	BCS_RESULT platform_result = init_platform();
	BCS_RESULT command_line_result = init_command_line(lpCmdLine);
	BCS_RESULT console_result = init_console();
	BCS_RESULT device_communication_result = init_device_communication();
	if(BCS_SUCCEEDED(console_result)) console_result = BCS_SUCCEEDED(command_line_has_argument("commandline")) ? alloc_console("Mandrill") : BCS_S_OK;
	BCS_RESULT window_create_result = window_create(window_title, "mandrill", _window_icon_mandrill, ULONG_MAX, ULONG_MAX, window_background_color, window);
	BCS_RESULT render_context_window_create_result = render_context_window_create(*window, graphics_background_color, window_render_context);

	mandrill_user_interface = new() c_mandrill_user_interface(
		*window_render_context,
		false, 
		launch_filepath_command_line_argument);

	window_render_context->render();

	delete mandrill_user_interface;

	if (BCS_SUCCEEDED(render_context_window_create_result)) render_context_window_create_result = render_context_destroy(window_render_context);
	if (BCS_SUCCEEDED(window_create_result)) window_create_result = window_destroy(window);
	if (BCS_SUCCEEDED(console_result)) console_result = deinit_console();
	if (BCS_SUCCEEDED(device_communication_result)) device_communication_result = deinit_device_communication();
	if (BCS_SUCCEEDED(command_line_result)) command_line_result = deinit_command_line();
	if (BCS_SUCCEEDED(platform_result)) platform_result = deinit_platform();

	BCS_FAIL_RETURN(render_context_window_create_result);
	BCS_FAIL_RETURN(window_create_result);
	BCS_FAIL_RETURN(console_result);
	BCS_FAIL_RETURN(command_line_result);
	BCS_FAIL_RETURN(platform_result);

	BCS_RESULT symbol_manager_cleanup_result = symbol_manager_cleanup();
	BCS_FAIL_RETURN(symbol_manager_cleanup_result);

	if (console_is_verbose())
	{
		print_memory_allocations();
	}

	return 0;
}
