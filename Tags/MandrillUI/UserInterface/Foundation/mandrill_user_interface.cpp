#include "mandrillui-private-pch.h"

t_get_tag_game_memory_callback* c_mandrill_user_interface::s_get_tag_game_memory = nullptr;
t_get_tag_section_address_callback* c_mandrill_user_interface::s_get_tag_section_address = nullptr;

bool c_mandrill_user_interface::use_developer_features = settings_read_boolean(_settings_section_mandrill, k_use_developer_features, false);
bool c_mandrill_user_interface::show_explorer_bar = settings_read_boolean(_settings_section_mandrill, k_show_explorer_bar, true);
float c_mandrill_user_interface::explorer_bar_width = settings_read_float(_settings_section_mandrill, k_explorer_bar_width, 500.0f);
bool c_mandrill_user_interface::show_console_bar = settings_read_boolean(_settings_section_mandrill, k_show_console_bar, false);

c_mandrill_user_interface::c_mandrill_user_interface(c_render_context& imgui_viewport_render_context, bool is_game_mode, const wchar_t* startup_file) :
	c_mandrill_tab("Mandrill", "", nullptr),
	c_imgui_status_interface(),
	imgui_viewport_render_context(imgui_viewport_render_context),
	is_session_restored(false),
	is_exiting(false),
	is_game_mode(is_game_mode),
	window_open(true),
	show_create_tag_project_file_dialogue(false),
	show_open_tag_project_file_dialogue(false),
	on_close(),
	on_render_foreground_handle(),
	mandrill_theme_color_count(0),
	mandrill_theme_var_count(0),
	file_browser()
{
	show_console_bar |= BCS_SUCCEEDED(command_line_has_argument("console"));

	c_fixed_path previous_file_path;
	settings_read_string(_settings_section_mandrill, k_previous_open_filepath_setting, previous_file_path.str(), previous_file_path.capacity(), "");
	if (!filesystem_directory_exists(previous_file_path.c_str()))
	{
		previous_file_path.clear();
	}
	//file_browser = new() ImGuiAddons::ImGuiFileBrowser(previous_file_path.c_str());

	restore_previous_session(false);
	restore_previous_session(true);
	open_cache_file_tab(startup_file);

	const wchar_t* auto_open_project;
	if (BCS_SUCCEEDED(command_line_get_argument(L"autoproject", auto_open_project)))
	{
		open_tag_project_configurator_tab(auto_open_project);
	}

	imgui_viewport_render_context.on_render_foreground.add_callback(on_render_foreground_callback, this, on_render_foreground_handle);
}

c_mandrill_user_interface::~c_mandrill_user_interface()
{
	save_current_session();

	is_exiting = true;

	//delete file_browser;
}

BCS_RESULT c_mandrill_user_interface::create_tag_project(const wchar_t* filepath, const char* tag_list)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_FAIL_RETURN(filesystem_filepath_exists(filepath));

	for (c_mandrill_tab* tab : children)
	{
		if (c_tag_project_tab* tag_project_tab = dynamic_cast<c_tag_project_tab*>(tab))
		{
			const wchar_t* project_filepath = tag_project_tab->project_filepath.c_str();
			if (BCS_SUCCEEDED(string_compare(project_filepath, filepath)))
			{
				next_selected_tab = tab;
				return BCS_S_OK;
			}
		}
	}

	return BCS_E_NOT_IMPLEMENTED; // #TODO: implement project creation tab
}

BCS_RESULT c_mandrill_user_interface::open_tag_project_tab(const wchar_t* filepath, const char* tag_list)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_FAIL_RETURN(filesystem_filepath_exists(filepath));

	for (c_mandrill_tab* tab : children)
	{
		if (c_tag_project_tab* tag_project_tab = dynamic_cast<c_tag_project_tab*>(tab))
		{
			// #TODO: open existing tab
		}
	}

	return BCS_E_NOT_IMPLEMENTED; // #TODO: implement project creation tab
}

BCS_RESULT c_mandrill_user_interface::open_tag_project_configurator_tab(const wchar_t* directory)
{
	c_tag_project_configurator_tab* tag_project_configurator_tab = new() c_tag_project_configurator_tab(directory, *this);
	add_tab(*tag_project_configurator_tab);
	next_selected_tab = tag_project_configurator_tab;
	return BCS_S_OK; // #TODO: return result from add_tab
}

BCS_RESULT c_mandrill_user_interface::open_cache_file_tab(const wchar_t* filepath, const char* tag_list)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_FAIL_RETURN(filesystem_filepath_exists(filepath));

	// #TODO: cache refactor
	/*
	for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
	{
		if (c_cache_file_tab* cache_file_tab = dynamic_cast<c_cache_file_tab*>(&tab))
		{
			const wchar_t* cache_filepath = cache_file_tab->get_cache_file	().get_map_filepath();
			if (wcscmp_ic(cache_filepath, filepath) == 0)
			{
				next_selected_tab = &tab;
				return;
			}
		}
	}

	if (c_cache_file* cache_file = c_cache_file::create_cache_file(filepath))
	{
		c_cache_file_tab* cache_file_tab = new() c_cache_file_tab(*cache_file, *this, tag_list);
		cache_file_tab->on_tab_added.register_callback(cache_file, [this](c_mandrill_tab& tab)
			{
				save_current_session();
			});
		cache_file_tab->on_tab_removed.register_callback(cache_file, [this](c_mandrill_tab& tab)
			{
				save_current_session();
			});
		cache_file_tab->on_selected_tree_change.register_callback(cache_file, [this](c_mandrill_tab& callee, c_mandrill_tab& target)
			{
				save_current_session();
			});
		cache_file_tab->on_closed.register_callback(cache_file, [this](c_mandrill_tab& tab)
			{
				if (c_cache_file_tab* cache_file_tab = dynamic_cast<c_cache_file_tab*>(&tab))
				{
					c_cache_file& cache_file = cache_file_tab->get_cache_file();
					delete& cache_file;
				}
			});
		add_tab(*cache_file_tab);
		next_selected_tab = cache_file_tab;
	}
	*/
	return BCS_E_NOT_IMPLEMENTED;
}

void c_mandrill_user_interface::restore_previous_session(bool use_projects)
{
	c_fixed_wide_string<32 * 1024> open_maps_buffer;
	if (use_projects)
	{
		settings_read_wstring(_settings_section_mandrill, k_previous_open_projects_setting, open_maps_buffer.str(), open_maps_buffer.capacity(), L"");
	}
	else
	{
		settings_read_wstring(_settings_section_mandrill, k_previous_open_maps_setting, open_maps_buffer.str(), open_maps_buffer.capacity(), L"");
	}


	c_fixed_wide_path selected_map_path;
	c_fixed_string_64k selected_map_tags_list;
	const wchar_t* const start_read_position = open_maps_buffer.c_str();
	const wchar_t* read_position = start_read_position;
	while (*read_position != 0)
	{
		c_fixed_wide_path map_path;

		if (*read_position == ';')
		{
			read_position++;
		}
		while (*read_position && *read_position != ';' && *read_position != '[' && *read_position != '*')
		{
			map_path += *read_position;
			read_position++;
		}
		bool is_selected = false;
		if (*read_position == '*')
		{
			is_selected = true;
			read_position++;
		}

		c_fixed_string_64k tags_list;
		if (*read_position == '[')
		{
			read_position++; // [
			while (*read_position && *read_position != ']')
			{
				tags_list += static_cast<char>(*read_position);
				read_position++;
			}
			read_position++; // ]
		}

		DEBUG_ASSERT(*read_position == 0 || *read_position == ';' || *read_position == '*');

		if (is_selected)
		{
			selected_map_path = map_path;
			selected_map_tags_list = tags_list;
		}

		if (use_projects)
		{
			open_tag_project_tab(map_path.c_str(), selected_map_tags_list.c_str());
		}
		else
		{
			open_cache_file_tab(map_path.c_str(), tags_list.c_str());
		}

		map_path.clear();
	}

	// #TODO: this is a hack. 
	// store a pointer to the selected tab, and make it selected using the pointer
	// rather than opening up the tab again
	if (!selected_map_path.empty())
	{
		if (use_projects)
		{
			open_tag_project_tab(selected_map_path.c_str(), selected_map_tags_list.c_str());
		}
		else
		{
			open_cache_file_tab(selected_map_path.c_str(), selected_map_tags_list.c_str());
		}
	}

	is_session_restored = true;
}

void c_mandrill_user_interface::save_current_session()
{
	if (!is_session_restored || is_exiting)
	{
		return;
	}

	c_fixed_wide_path open_maps_path;
	c_fixed_wide_path open_projects_path;
	for (c_mandrill_tab* tab : children)
	{
		if (c_tag_project_tab* tag_project_tab = dynamic_cast<c_tag_project_tab*>(tab))
		{
			c_tag_project& tag_project = tag_project_tab->get_tag_project();

			if (!open_projects_path.empty())
			{
				open_projects_path += ';';
			}
			open_projects_path += tag_project_tab->project_filepath.c_str();

			if (tab->is_selected())
			{
				open_projects_path += "*";
			}

			unsigned long cache_file_tab_index = 0;

			unsigned long tag_project_tab_child_count = tag_project_tab->get_child_count();
			c_mandrill_tab*const* tag_project_tab_children = tag_project_tab->get_children();
			for(unsigned long tab_index =0;tab_index < tag_project_tab_child_count; tab_index++)
			{
				c_mandrill_tab* tab = tag_project_tab_children[tab_index];
				if (c_high_level_tag_tab* high_level_tag_tab = dynamic_cast<c_high_level_tag_tab*>(tab))
				{
					if (cache_file_tab_index == 0)
					{
						open_projects_path += '[';
					}
					else
					{
						open_projects_path += ';';
					}

					open_projects_path += high_level_tag_tab->get_tag().tag_filepath.c_str();

					if (high_level_tag_tab->is_selected())
					{
						open_projects_path += "*";
					}

					cache_file_tab_index++;
				}
			}
			if (cache_file_tab_index > 0)
			{
				open_projects_path += ']';
			}
		}
	}

	settings_write_wstring(_settings_section_mandrill, k_previous_open_maps_setting, open_maps_path.c_str());
	settings_write_wstring(_settings_section_mandrill, k_previous_open_projects_setting, open_projects_path.c_str());
}

void c_mandrill_user_interface::render()
{
	render_impl();
}

void c_mandrill_user_interface::render_game_layer()
{
	render_game_layer_impl();
}

void c_mandrill_user_interface::on_render_foreground_callback(c_mandrill_user_interface& _this)
{
	_this.render();
}

void c_mandrill_user_interface::set_get_tag_section_address_callback(t_get_tag_section_address_callback* get_tag_section_address)
{
	s_get_tag_section_address = get_tag_section_address;
}

void c_mandrill_user_interface::set_get_tag_game_memory_callback(t_get_tag_game_memory_callback* get_tag_game_memory)
{
	s_get_tag_game_memory = get_tag_game_memory;
}

void c_mandrill_user_interface::render_impl()
{
	mandrill_theme_push();

	float margin = 4.0f;

	ImGuiWindowFlags imgui_main_window_flags = 0;
	imgui_main_window_flags |= ImGuiWindowFlags_NoCollapse;
	imgui_main_window_flags |= ImGuiWindowFlags_MenuBar;
	imgui_main_window_flags |= ImGuiWindowFlags_NoSavedSettings;
	ImVec2 main_window_position = { margin, margin };
	ImVec2 main_window_size;
	float console_bar_height = show_console_bar ? 500.0f : 0.0f;
	if (is_game_mode)
	{
		ImGui::SetNextWindowPos(main_window_position, ImGuiCond_FirstUseEver);
		main_window_size =
		{
			imgui_viewport_render_context.get_width_float() - margin * 2.0f,
			imgui_viewport_render_context.get_height_float() - margin * 2.0f
		};
		ImGui::SetNextWindowSize(main_window_size, ImGuiCond_FirstUseEver);
	}
	else
	{
		float status_bar_height = ImGui::GetFrameHeight();
		ImGui::SetNextWindowPos(main_window_position, ImGuiCond_Always);
		main_window_size =
		{
			imgui_viewport_render_context.get_width_float() - margin * 2.0f, 
			imgui_viewport_render_context.get_height_float() - margin * 2.0f - status_bar_height - console_bar_height
		};
		ImGui::SetNextWindowSize(main_window_size, ImGuiCond_Always);

		imgui_main_window_flags |= ImGuiWindowFlags_NoTitleBar;
		imgui_main_window_flags |= ImGuiWindowFlags_NoMove;
		imgui_main_window_flags |= ImGuiWindowFlags_NoResize;
		imgui_main_window_flags |= ImGuiWindowFlags_NoScrollbar;
	}

	render_file_dialogue_gui_impl();

	if (ImGui::Begin("Mandrill", &window_open, imgui_main_window_flags))
	{
		ImGuiIO& io = ImGui::GetIO();

		ImVec2 window_start_position = ImGui::GetCursorPos();

		render_menu_gui_impl(_menu_render_type_root);
		render_menu_gui_impl(_menu_render_type_status_bar);

		if (ImGui::BeginTabBar("##root"))
		{
			c_mandrill_tab* next_selected_tab_temp = next_selected_tab; // read as children can invalidate this value

			next_selected_tab = nullptr;
			auto children_copy = children; // #TODO: remove the requirement for this copy
			for (c_mandrill_tab* tab : children_copy)
			{
				tab->render(next_selected_tab_temp == tab);
			}

			ImGui::EndTabBar();
		}

		ImVec2 cursor_start_position = ImGui::GetCursorPos();
		{
			ImVec4 username_colors[] =
			{
				{ 0.8f, 0.0f, 0.0f, 1.0f },
				ImGui::GetStyleColorVec4(ImGuiCol_Text),
				{ 0.8f, 0.42f, 0.0f, 1.0f },
				{ 0.0f, 0.48f, 0.8f, 1.0f },
				{ 0.18f, 0.8f, 0.39f, 1.0f },
			};
			static long user_type = keys_user_type();
			if (user_type >= 3)
			{
				long user_type_color_index = __min(_countof(username_colors) - 1, user_type);
				ImVec4& color = username_colors[user_type_color_index];
				ImGui::PushStyleColor(ImGuiCol_Text, color);

				char buffer[256];
				const char* username = keys_user_name();
				unsigned long discriminator = keys_user_discriminator();
				snprintf(buffer, sizeof(buffer), "%s#%lu", username, discriminator);

				float content_region_width = ImGui::GetContentRegionAvailWidth();
				ImVec2 text_size = ImGui::CalcTextSize(buffer);
				ImGui::SetCursorPos({ window_start_position.x + (content_region_width - text_size.x), window_start_position.y });
				ImGui::TextUnformatted(buffer);

				ImGui::PopStyleColor();
			}
			else if(user_type == 0)
			{
				ImVec4& color = username_colors[0];
				ImGui::PushStyleColor(ImGuiCol_Text, color);

				const char* text = "Limited Access";
				float content_region_width = ImGui::GetContentRegionAvailWidth();
				ImVec2 text_size = ImGui::CalcTextSize(text);
				ImVec2 item_spacing = ImGui::GetStyle().ItemSpacing;
				ImGui::SetCursorPos({ window_start_position.x + (content_region_width - (text_size.x + item_spacing.x)), window_start_position.y });
				ImGui::TextUnformatted(text);

				ImGui::PopStyleColor();
			}
		}
		ImGui::SetCursorPos(cursor_start_position);
	}
	ImGui::End();
	if (show_console_bar)
	{
		ImGuiWindowFlags imgui_console_window_flags = 0;
		imgui_console_window_flags |= ImGuiWindowFlags_NoCollapse;
		imgui_console_window_flags |= ImGuiWindowFlags_NoSavedSettings;
		imgui_console_window_flags |= ImGuiWindowFlags_NoMove;
		imgui_console_window_flags |= ImGuiWindowFlags_NoResize;
		imgui_console_window_flags |= ImGuiWindowFlags_NoScrollbar;

		ImVec2 console_window_position = main_window_position + ImVec2{ 0.0f, main_window_size.y + margin };
		ImVec2 console_window_size = { main_window_size.x, console_bar_height - margin };

		ImGui::SetNextWindowPos(console_window_position, ImGuiCond_Always);
		ImGui::SetNextWindowSize(console_window_size, ImGuiCond_Always);

		if (ImGui::Begin("Console", &show_console_bar, imgui_console_window_flags))
		{

		}
		if (!show_console_bar)
		{
			settings_write_boolean(_settings_section_mandrill, k_show_console_bar, show_console_bar);
		}
		ImGui::End();
	}

	mandrill_theme_pop();

	if (!_is_open)
	{
		on_close();
	}
}

bool c_mandrill_user_interface::render_menu_gui_impl(e_menu_render_type menu_render_type)
{
	if (menu_render_type == _menu_render_type_root)
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("New Project"))
				{
					show_create_tag_project_file_dialogue = true;
				}
				if (ImGui::MenuItem("Open Project"))
				{
					show_open_tag_project_file_dialogue = true;
				}
				ImGui::Separator();
				for (c_mandrill_tab* tab : children)
				{
					tab->render_menu_gui(_menu_render_type_root_file);
				}
				//ImGui::MenuItem("Save Workspace");
				//ImGui::MenuItem("Load Workspace");
				//ImGui::Separator();
				if (ImGui::MenuItem("Exit", "Alt+F4"))
				{
					_is_open = false;
				}
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Edit"))
			{
				ImGui::MenuItem("Undo");
				ImGui::Separator();
				ImGui::MenuItem("Cut");
				ImGui::MenuItem("Copy");
				ImGui::MenuItem("Paste");
				ImGui::MenuItem("Clear");
				ImGui::Separator();
				ImGui::MenuItem("Expert Mode");
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("View"))
			{
				if (ImGui::MenuItem(show_explorer_bar ? "Hide Explorer Bar" : "Show Explorer Bar"))
				{
					show_explorer_bar = !show_explorer_bar;
					settings_write_boolean(_settings_section_mandrill, k_show_explorer_bar, show_explorer_bar);
				}

				ImGui::Separator();

				if (ImGui::MenuItem(use_developer_features ? "Disable Developer Features" : "Enable Developer Features"))
				{
					use_developer_features = !use_developer_features;
					settings_write_boolean(_settings_section_mandrill, k_use_developer_features, use_developer_features);
				}

				ImGui::EndMenu();
			}
			for (c_mandrill_tab* tab : children)
			{
				tab->render_menu_gui(_menu_render_type_root);
			}
			if (ImGui::BeginMenu("Help"))
			{
				ImGui::MenuItem("Read Me");
				ImGui::MenuItem("About");
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
	}
	if (menu_render_type == _menu_render_type_status_bar)
	{
		ImGuiViewportP* viewport = (ImGuiViewportP*)(void*)ImGui::GetMainViewport();
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;
		float height = ImGui::GetFrameHeight();

		if (ImGui::BeginViewportSideBar("##MainStatusBar", viewport, ImGuiDir_Down, height, window_flags)) {
			if (ImGui::BeginMenuBar()) {
				ImGui::TextUnformatted(get_status_bar_text());

				static ImVec2 gamepad_size;
				static ImVec2 terminal_size;

				ImVec2 start_cursor_pos = ImGui::GetCursorPos();
				float content_region_width = ImGui::GetContentRegionAvailWidth();
				start_cursor_pos.x += content_region_width;
				start_cursor_pos.x -= gamepad_size.x;
				start_cursor_pos.x -= terminal_size.x;
				ImGui::SetCursorPosX(start_cursor_pos.x);

				if (ImGui::BeginMenu(ICON_FA_NETWORK_WIRED))
				{
					s_xbox360_device_entry const* devices;
					unsigned long device_count;
					if (BCS_SUCCEEDED(xbox360_device_manager_get_devices(devices, device_count)))
					{
						for (unsigned long device_index = 0; device_index < device_count; device_index++)
						{
							s_xbox360_device_entry const& device = devices[device_index];
							size_t buffer_length = snprintf(nullptr, 0, ICON_FA_XBOX " %s", device.console_value_name_buffer_mb) + 1;
							char* device_display_buffer = new char[buffer_length];
							sprintf(device_display_buffer, ICON_FA_XBOX " %s", device.console_value_name_buffer_mb);
							ImGui::MenuItem(device_display_buffer);
							delete[] device_display_buffer;
						}
						ImGui::Separator();
					}
					ImGui::BeginDisabled(true);
					ImGui::MenuItem("Add Xbox 360 Console");
					ImGui::EndDisabled();
					ImGui::EndMenu();
				}
				ImVec2 gamepad_end_pos = ImGui::GetCursorPos();
				if (ImGui::MenuItem(ICON_FA_TERMINAL))
				{
					show_console_bar = !show_console_bar;
					settings_write_boolean(_settings_section_mandrill, k_show_console_bar, show_console_bar);
				}
				ImVec2 terminal_end_pos = ImGui::GetCursorPos();

				gamepad_size = gamepad_end_pos - start_cursor_pos;
				terminal_size = terminal_end_pos - gamepad_end_pos;

				ImGui::EndMenuBar();
			}
			ImGui::End();
		}
	}
	return false;
}

void c_mandrill_user_interface::render_file_dialogue_gui_impl()
{
	if (ImGui::BeginAsyncOpenFolderDialog(&file_browser, "Create Tag Project", show_create_tag_project_file_dialogue))
	{
		if (ImGui::AsyncFileDialogIsValid())
		{
			const wchar_t* filepath = ImGui::AsyncFileDialogGetFilepathWideChar();

			settings_write_wstring(_settings_section_mandrill, k_previous_open_filepath_setting, filepath);
			open_tag_project_configurator_tab(filepath);

			debug_point;
		}
		debug_point;

		ImGui::EndAsyncFileDialog();
	}
	show_create_tag_project_file_dialogue = false;

	if (ImGui::BeginAsyncOpenFileDialog(&file_browser, "Open Tag Project", show_open_tag_project_file_dialogue))
	{
		if (ImGui::AsyncFileDialogIsValid())
		{
			const wchar_t* filepath = ImGui::AsyncFileDialogGetFilepathWideChar();

			settings_write_wstring(_settings_section_mandrill, k_previous_open_filepath_setting, filepath);
			//open_tag_project_configurator_tab(filepath);

			debug_point;
		}
		debug_point;

		ImGui::EndAsyncFileDialog();
	}
	show_open_tag_project_file_dialogue = false;

	for (c_mandrill_tab* tab : children)
	{
		tab->render_file_dialogue_gui();
	}
}

void c_mandrill_user_interface::render_game_layer_impl()
{
	for (c_mandrill_tab* tab : children)
	{
		tab->render_game_layer();
	}
}

void c_mandrill_user_interface::add_tab(c_mandrill_tab& tab)
{
	c_mandrill_tab_container::add_tab(tab);
	save_current_session();
}

void c_mandrill_user_interface::remove_tab(c_mandrill_tab& tab)
{
	c_mandrill_tab_container::remove_tab(tab);
	save_current_session();
}

void c_mandrill_user_interface::mandrill_theme_push()
{
#define push_color4_float(color, r, g, b, a) mandrill_theme_color_count++; ImGui::PushStyleColor(color, ImVec4(float(r), float(g), float(b), float(a)))
#define push_color3_float(color, r, g, b) push_color4_float(color, r, g, b, 1.0f)
#define push_color4(color, r, g, b, a) push_color4_float(color, float(r) / 255.0f, float(g) / 255.0f, float(b) / 255.0f, 1.0f)
#define push_color3(color, r, g, b) push_color4(color, r, g, b, 255)
#define push_color(color, value) mandrill_theme_color_count++; ImGui::PushStyleColor(color, value)
#define push_style(style, ...) mandrill_theme_var_count++; ImGui::PushStyleVar(style, __VA_ARGS__)

	mandrill_theme_color_count = 0;
	mandrill_theme_var_count = 0;

	push_color(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.78f));
	push_color(ImGuiCol_TextDisabled, MANDRILL_THEME_TEXT(0.28f));
	push_color(ImGuiCol_WindowBg, ImVec4(0.13f, 0.14f, 0.17f, 1.00f));
	push_color(ImGuiCol_ChildBg, MANDRILL_THEME_BG(0.15f));
	push_color(ImGuiCol_PopupBg, MANDRILL_THEME_BG(0.9f));
	push_color(ImGuiCol_Border, ImVec4(0.31f, 0.31f, 1.00f, 0.00f));
	push_color(ImGuiCol_BorderShadow, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));
	push_color(ImGuiCol_FrameBg, MANDRILL_THEME_BG(1.00f));
	push_color(ImGuiCol_FrameBgHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_FrameBgActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TitleBg, MANDRILL_THEME_LOW(1.00f));
	push_color(ImGuiCol_TitleBgActive, MANDRILL_THEME_HIGH(1.00f));
	push_color(ImGuiCol_TitleBgCollapsed, MANDRILL_THEME_BG(0.75f));
	push_color(ImGuiCol_MenuBarBg, MANDRILL_THEME_BG(0.47f));
	push_color(ImGuiCol_ScrollbarBg, MANDRILL_THEME_BG(1.00f));
	push_color(ImGuiCol_ScrollbarGrab, ImVec4(0.09f, 0.15f, 0.16f, 1.00f));
	push_color(ImGuiCol_ScrollbarGrabHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_ScrollbarGrabActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_CheckMark, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_SliderGrab, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_SliderGrabActive, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_Button, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_ButtonHovered, MANDRILL_THEME_MED(0.86f));
	push_color(ImGuiCol_ButtonActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_Header, MANDRILL_THEME_MED(0.76f));
	push_color(ImGuiCol_HeaderHovered, MANDRILL_THEME_MED(0.86f));
	push_color(ImGuiCol_HeaderActive, MANDRILL_THEME_HIGH(1.00f));
	//push_color(ImGuiCol_Column, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	//push_color(ImGuiCol_ColumnHovered, MANDRILL_THEME_MED(0.78f));
	//push_color(ImGuiCol_ColumnActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_ResizeGrip, ImVec4(0.47f, 0.77f, 0.83f, 0.04f));
	push_color(ImGuiCol_ResizeGripHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_ResizeGripActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_PlotLines, MANDRILL_THEME_TEXT(0.63f));
	push_color(ImGuiCol_PlotLinesHovered, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_PlotHistogram, MANDRILL_THEME_TEXT(0.63f));
	push_color(ImGuiCol_PlotHistogramHovered, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TextSelectedBg, MANDRILL_THEME_MED(0.43f));
	//push_color(ImGuiCol_ModalWindowDarkening, MANDRILL_THEME_BG(0.73f));

	push_color(ImGuiCol_Tab, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	push_color(ImGuiCol_TabHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_TabActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TabUnfocused, MANDRILL_THEME_LOW(0.78f));


	//push_color3(ImGuiCol_WindowBg, 33, 33, 33);
	push_color(ImGuiCol_MenuBarBg, MANDRILL_THEME_MENU(1.0f));

	push_style(ImGuiStyleVar_WindowPadding, { 4, 8 });
	push_style(ImGuiStyleVar_ScrollbarSize, { 20 });
	push_style(ImGuiStyleVar_ItemInnerSpacing, { 5, 4 });

	push_style(ImGuiStyleVar_WindowRounding, { 0 });
	push_style(ImGuiStyleVar_ScrollbarRounding, { 0 });
	push_style(ImGuiStyleVar_TabRounding, { 0 });

#undef push_color4_float
#undef push_color3_float
#undef push_color4
#undef push_color3
#undef push_style
}

void c_mandrill_user_interface::mandrill_theme_pop()
{
	ImGui::PopStyleColor(mandrill_theme_color_count);
	ImGui::PopStyleVar(mandrill_theme_var_count);
}
