﻿#include "halo1lib-private-pch.h"

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

c_game_runtime* c_halo1_game_host::g_halo1_game_runtime;
static c_halo1_engine_state_command* g_halo1_engine_state_command;
static c_halo1_halo_script_command* g_halo1_halo_script_command;

/* ---------- private prototypes */
/* ---------- public code */

#include "halo1_game_host.testing.inl"
#include "halo1_game_host.scripting.inl"
#include "halo1_game_host.console.inl"
#include "halo1_game_host.controls_research.inl"

uintptr_t g_keyboard_state_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18218CE20);
	return ~uintptr_t();
}
uint8_t(&g_keyboard_state)[218] = reference_symbol<uint8_t[218]>("g_keyboard_state", g_keyboard_state_offset);

void register_halo1lib()
{

}

c_halo1_game_host::c_halo1_game_host(e_engine_type engine_type, e_build build) :
	c_opus_game_engine_host(engine_type, build, get_game_runtime())
{
	write_line_verbose("Init Halo1GameHost");

	init_runtime_modifications(g_halo1_game_runtime->get_build());

	if (game_engine == nullptr)
	{
		__int64 create_game_engine_result = get_game_runtime().CreateGameEngine(&game_engine);
	}
	ASSERT(game_engine != nullptr);

	if (g_halo1_engine_state_command != nullptr)
	{
		g_halo1_engine_state_command->set_game_engine(game_engine);
	}

	c_debug_gui::register_callback(_callback_mode_always_run, input_debug_gui);
}

c_halo1_game_host::~c_halo1_game_host()
{
	write_line_verbose("Deinit Halo1GameHost");

	c_mantle_gui::set_get_tag_selection_address_function(nullptr); // #TODO: This is kinda hacky
	c_mantle_gui::set_get_tag_pointer_function(nullptr); // #TODO: This is kinda hacky

	//m_pGameEngine->Destructor();
	//free(pHaloReachEngine);
	//free(pHaloReachDataAccess);

	//m_pGameEngine = nullptr;

	deinit_runtime_modifications(g_halo1_game_runtime->get_build());

	c_game_runtime& halo1_game_runtime = get_game_runtime();
	halo1_game_runtime.~c_game_runtime();
	new(&halo1_game_runtime) c_game_runtime(_engine_type_halo1, "halo1", "Halo1\\halo1.dll");
}

void c_halo1_game_host::FrameEnd(IDXGISwapChain* swap_chain, _QWORD unknown1)
{
	if (GetAsyncKeyState(VK_F10))
	{
		get_game_engine()->UpdateEngineState(eEngineState::EndGame);
	}



	update_camera_data();
	c_opus_game_engine_host::FrameEnd(swap_chain, unknown1);
}

void c_halo1_game_host::render_ui() const
{
	draw_camera_debug_ui();
}

IGameEngine* c_halo1_game_host::get_game_engine() const
{
	return game_engine;
}

c_game_runtime& c_halo1_game_host::get_game_runtime()
{
	if (g_halo1_game_runtime == nullptr)
	{
		g_halo1_game_runtime = new c_game_runtime(_engine_type_halo1, "halo1", "Halo1\\halo1.dll");
	}

	return *g_halo1_game_runtime;
}

uint64_t powui64(uint64_t value, uint64_t power)
{
	uint64_t result = 1;

	for (uint64_t i = 0; i < power; i++)
	{
		result *= value;
	}

	return result;
}

decltype(_ui64tow_s)* ui64tow_s_original = nullptr;
errno_t __cdecl _ui64tow_s_hook(
	_In_                         unsigned __int64 _Value,
	_Out_writes_z_(_BufferCount) wchar_t* _Buffer,
	_In_                         size_t           _BufferCount,
	_In_                         int              _Radix
)
{
	uint64_t max_value_for_buffer = powui64(10, _BufferCount - 1) - 1;
	if (_Value < max_value_for_buffer)
	{
		return ui64tow_s_original(_Value, _Buffer, _BufferCount, _Radix);
	}
	else
	{
		_Buffer[0] = L'0';
		_Buffer[1] = 0;
		return 0;
	}
}

void c_halo1_game_host::init_runtime_modifications(e_build build)
{
	g_halo1_engine_state_command = new c_halo1_engine_state_command();
	g_halo1_halo_script_command = new c_halo1_halo_script_command();

	init_detours();	
	
	create_dll_hook("api-ms-win-crt-convert-l1-1-0.dll", "_ui64tow_s", _ui64tow_s_hook, ui64tow_s_original);

	c_global_reference::init_global_reference_tree(_engine_type_halo1, build);
	c_data_patch_base::init_data_patch_tree(_engine_type_halo1, build);
	c_function_hook_base::init_function_hook_tree(_engine_type_halo1, build);
	end_detours();
}

void c_halo1_game_host::deinit_runtime_modifications(e_build build)
{
	delete g_halo1_engine_state_command;
	delete g_halo1_halo_script_command;

	init_detours();
	c_function_hook_base::deinit_function_hook_tree(_engine_type_halo1, build);
	c_data_patch_base::deinit_data_patch_tree(_engine_type_halo1, build);
	c_global_reference::deinit_global_reference_tree(_engine_type_halo1, build);
	end_detours();
}

/* ---------- private code */

void c_halo1_game_host::update_camera_data()
{
	//if (!player_mapping_get_local_player.m_isHooked) return;
	//if (!observer_try_and_get_camera.m_isHooked) return;

	//int playerIndex = player_mapping_get_local_player();
	//s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);
	//if (observer_camera)
	//{
	//	float aspectRatio = 16.0f / 9.0f; // #TODO: Correct aspect ratio
	//	float fieldOfViewHorizontal = observer_camera->field_of_view;
	//	c_render::UpdatePerspective(fieldOfViewHorizontal, aspectRatio);
	//	c_render::UpdateView(
	//		observer_camera->forward.I,
	//		observer_camera->forward.J,
	//		observer_camera->forward.K,
	//		observer_camera->up.I,
	//		observer_camera->up.J,
	//		observer_camera->up.K,
	//		observer_camera->position.I,
	//		observer_camera->position.J,
	//		observer_camera->position.K
	//	);
	//}
}



void c_halo1_game_host::input_debug_gui() 
{
	return;
#ifdef __HALO1_GAME_HOST_CONTROLS_RESEARCH_INL
	ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(600, 1300), ImGuiCond_FirstUseEver);

	if (ImGui::Begin("Key Debug"))
	{
		ImGui::Text("g_GameInputSource %i", g_GameInputSource);

		ImGui::Checkbox("sub_18071E950_override", &sub_18071E950_override);
		ImGui::InputInt("sub_18071E950_override_value", &sub_18071E950_override_value);
		ImGui::Text("sub_18071E950_state %u", static_cast<uint32_t>(sub_18071E950_state));

		ImGui::Checkbox("sub_18071E690_override", &sub_18071E690_override);
		ImGui::InputInt("sub_18071E690_override_value", &sub_18071E690_override_value);
		ImGui::Text("sub_18071E690_state_state %u", static_cast<uint32_t>(sub_18071E690_state));
		if (is_valid(dword_18115BB84))
		{
			ImGui::Text("dword_18115BB84 %d", dword_18115BB84);
		}



		ImGui::Separator();

		if (is_valid(word_18115BBB6))
		{
			for (int i = 0; i < 128; i++)
			{
				ImGui::Text("Bind %i [%u]", i, static_cast<uint32_t>(word_18115BBB6[i]));
				if ((i - 3) % 4 != 0) ImGui::SameLine();
			}
		}

		//if (is_valid(g_keyboard_state))
		//{
		//	for (int i = 0; i < 218; i++)
		//	{
		//		ImGui::Text("Key %i [%u]", i, static_cast<uint32_t>(g_keyboard_state[i]));
		//		if ((i - 3) % 4 != 0) ImGui::SameLine();
		//	}
		//}
	}
	ImGui::End();
#endif
}

uintptr_t sub_1806F4000_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1806F4000);
	return ~uintptr_t();
}
FunctionHookEx<sub_1806F4000_offset, void()> sub_1806F4000 = { "sub_1806F4000", []() {

	sub_1806F4000();
	debug_point;

} };

uintptr_t sub_1800935B0_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1800935B0);
	return ~uintptr_t();
}
FunctionHookEx<sub_1800935B0_offset, __int64 __fastcall (__int64 a1)> sub_1800935B0 = { "sub_1800935B0", [](__int64 a1) {

	uint32_t sub_1806F4000_reference_count = sub_1806F4000.reference_counter;

	if (sub_1806F4000_reference_count > 0)
	{
		return __int64(0);
	}
	else
	{
		__int64 result = sub_1800935B0(a1);
		return result;
	}

} };

void c_halo1_game_host::draw_camera_debug_ui()
{
	draw_console_debug_gui();

	ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(600, 600), ImGuiCond_FirstUseEver);


	static const bool k_enable_camera_debug_test = c_command_line::has_command_line_arg("-cameradebug");
	if (k_enable_camera_debug_test)
	{
		//ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
		//ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

		//// Main body of the Demo window starts here.
		//static bool isReachCameraDebugWindowOpen = true;
		//if (ImGui::Begin("Camera Debug Output", &isReachCameraDebugWindowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
		//{
		//	int playerIndex = player_mapping_get_local_player();
		//	s_observer_camera* observer_camera = observer_try_and_get_camera(playerIndex);

		//	if (observer_camera)
		//	{
		//		ImGui::Text("position:       %f, %f, %f", observer_camera->position.I, observer_camera->position.J, observer_camera->position.K);
		//		ImGui::Text("position_shift: %f, %f, %f", observer_camera->position_shift.I, observer_camera->position_shift.J, observer_camera->position_shift.K);
		//		ImGui::Text("look:           %f", observer_camera->look);
		//		ImGui::Text("look_shift:     %f", observer_camera->look_shift);
		//		ImGui::Text("depth:          %f", observer_camera->depth);
		//		ImGui::Text("unknown0:       %f", observer_camera->unknown0);
		//		ImGui::Text("forward:        %f, %f, %f", observer_camera->forward.I, observer_camera->forward.J, observer_camera->forward.K);
		//		ImGui::Text("up:             %f, %f, %f", observer_camera->up.I, observer_camera->up.J, observer_camera->up.K);
		//		ImGui::Text("field_of_view:  %f", observer_camera->field_of_view);
		//		ImGui::Text("unknown1:       %f", observer_camera->unknown1);
		//		ImGui::Text("unknown2:       %f", observer_camera->unknown2);
		//	}
		//	else ImGui::Text("No camera present.");
		//}
		//ImGui::End();
	}
}