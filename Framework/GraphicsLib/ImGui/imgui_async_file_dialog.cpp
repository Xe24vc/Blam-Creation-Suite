#include "graphicslib-private-pch.h"

#include <Shobjidl_core.h>

static thread_local s_imgui_async_file_dialog_handle** current_file_dialog_handle = nullptr;

template <class T> static void SafeRelease(T** ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}

DWORD WINAPI file_dialogue_routine(LPVOID lpThreadParameter)
{
	s_imgui_async_file_dialog_handle* imgui_file_dialog_handle = static_cast<s_imgui_async_file_dialog_handle*>(lpThreadParameter);
	ASSERT(imgui_file_dialog_handle != nullptr);

	HRESULT thread_result = S_OK;

	IFileDialog* file_dialog = nullptr;
	IShellItem* shell_item = nullptr;
	LPWSTR filepath_widechar = NULL;
	DWORD file_dialog_options = 0;

	// #NOTE: make sure to pull parameters out before they get squashed
	const char* window_title = imgui_file_dialog_handle->window_title;
	HWND owner_window = imgui_file_dialog_handle->owner_window;
	bool is_open_file_dialog = imgui_file_dialog_handle->is_open_file_dialog;
	bool is_save_file_dialog = imgui_file_dialog_handle->is_save_file_dialog;
	BCS_CHAR_TO_WIDECHAR_STACK(window_title, window_title_wc);

	imgui_file_dialog_handle->filepath_widechar = nullptr;
	imgui_file_dialog_handle->filepath_multibyte = nullptr;

	if (is_open_file_dialog)
	{
		if (FAILED(thread_result = CoCreateInstance(__uuidof(FileOpenDialog), NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&file_dialog))))
		{
			goto done;
		}
	}
	else if (is_save_file_dialog)
	{
		if (FAILED(thread_result = CoCreateInstance(__uuidof(FileSaveDialog), NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&file_dialog))))
		{
			goto done;
		}
	}
	else FATAL_ERROR("Unknown dialog type");

	if (imgui_file_dialog_handle->is_folder_dialog)
	{
		if (FAILED(thread_result = file_dialog->GetOptions(&file_dialog_options)))
		{
			goto done;
		}

		file_dialog_options |= FOS_PICKFOLDERS;

		if (FAILED(thread_result = file_dialog->SetOptions(file_dialog_options)))
		{
			goto done;
		}
	}

	if (FAILED(thread_result = file_dialog->SetTitle(window_title_wc)))
	{
		goto done;
	}

	thread_result = file_dialog->Show(owner_window);
	if (thread_result == HRESULT_FROM_WIN32(ERROR_CANCELLED))
	{
		// User cancelled.
		imgui_file_dialog_handle->user_cancelled = true;
		thread_result = S_OK;
		goto done;
	}

	if (FAILED(thread_result = file_dialog->GetResult(&shell_item)))
	{
		goto done;
	}

	if (FAILED(thread_result = shell_item->GetDisplayName(SIGDN_FILESYSPATH, &filepath_widechar)))
	{
		goto done;
	}

	if (imgui_file_dialog_handle->is_folder_dialog)
	{
		size_t filepath_length = wcslen(filepath_widechar);
		imgui_file_dialog_handle->filepath_widechar = new wchar_t[filepath_length + 2];
		wcscpy(imgui_file_dialog_handle->filepath_widechar, filepath_widechar);
		imgui_file_dialog_handle->filepath_widechar[filepath_length] = '\\';
		imgui_file_dialog_handle->filepath_widechar[filepath_length + 1] = 0;

		debug_point;
	}
	else
	{
		size_t filepath_length = wcslen(filepath_widechar);
		imgui_file_dialog_handle->filepath_widechar = new wchar_t[filepath_length + 1];
		wcscpy(imgui_file_dialog_handle->filepath_widechar, filepath_widechar);
		imgui_file_dialog_handle->filepath_widechar[filepath_length] = 0;

		debug_point;
	}

	{
		BCS_WIDECHAR_TO_CHAR_HEAP(imgui_file_dialog_handle->filepath_widechar, filepath_multibyte);
		imgui_file_dialog_handle->filepath_multibyte = filepath_multibyte;
	}

done:
	CoTaskMemFree(filepath_widechar);
	untracked_free(window_title);
	SafeRelease(&shell_item);
	SafeRelease(&file_dialog);

	imgui_file_dialog_handle->file_dialog_result = thread_result;
	return thread_result;
}

bool BeginAsyncFileFolderDialog(
	t_imgui_async_file_dialog_handle* _file_dialog_handle,
	const char* window_title,
	bool show,
	void* owner_window_handle,
	bool is_file_dialog,
	bool is_folder_dialog,
	bool is_open_file_dialog,
	bool is_save_file_dialog)
{
	current_file_dialog_handle = _file_dialog_handle;

	ImGuiID imgui_id = ImGui::GetID(window_title);

	s_imgui_async_file_dialog_handle*& file_dialog_handle = *_file_dialog_handle;
	if (show && file_dialog_handle == nullptr)
	{
		file_dialog_handle = new() s_imgui_async_file_dialog_handle{};

		file_dialog_handle->ready_to_dispose = 0;
		file_dialog_handle->thread_handle = CreateThread(NULL, 0, file_dialogue_routine, file_dialog_handle, 0, NULL);
		file_dialog_handle->thread_wait_result = S_OK;
		file_dialog_handle->file_dialog_result = S_OK;
		file_dialog_handle->filepath_multibyte = nullptr;
		file_dialog_handle->filepath_widechar = nullptr;
		file_dialog_handle->window_title = _strdup(window_title); // freed in thread
		file_dialog_handle->owner_window = reinterpret_cast<HWND>(owner_window_handle);
		file_dialog_handle->is_folder_dialog = is_folder_dialog;
		file_dialog_handle->is_file_dialog = is_file_dialog;
		file_dialog_handle->is_open_file_dialog = is_open_file_dialog;
		file_dialog_handle->is_save_file_dialog = is_save_file_dialog;
		file_dialog_handle->imgui_id = imgui_id;

	}
	if (file_dialog_handle != nullptr && file_dialog_handle->imgui_id == imgui_id)
	{
		HRESULT thread_wait_result = file_dialog_handle->thread_wait_result = WaitForSingleObject(file_dialog_handle->thread_handle, 0);
		if (FAILED(thread_wait_result))
		{
			file_dialog_handle->ready_to_dispose = true;
			file_dialog_handle->error = true;

			debug_point;
		}
		else if (thread_wait_result != WAIT_TIMEOUT)
		{
			// thread has completed, grab info

			HRESULT file_dialog_result = file_dialog_handle->file_dialog_result;
			file_dialog_handle->ready_to_dispose = true;
			file_dialog_handle->error = FAILED(file_dialog_result);

			debug_point;
		}
	}
	return file_dialog_handle && file_dialog_handle->ready_to_dispose;
}

bool ImGui::BeginAsyncOpenFileDialog(
	t_imgui_async_file_dialog_handle* file_dialog_handle,
	const char* window_title, 
	bool show,
	void* owner_window_handle)
{
	return BeginAsyncFileFolderDialog(
		file_dialog_handle,
		window_title,
		show,
		owner_window_handle,
		true,
		false,
		true,
		false);
}

bool ImGui::BeginAsyncOpenFolderDialog(
	t_imgui_async_file_dialog_handle* file_dialog_handle,
	const char* window_title,
	bool show,
	void* owner_window_handle)
{
	return BeginAsyncFileFolderDialog(
		file_dialog_handle,
		window_title,
		show,
		owner_window_handle,
		false,
		true,
		true,
		false);
}

bool ImGui::BeginAsyncSaveFileDialog(
	t_imgui_async_file_dialog_handle* file_dialog_handle,
	const char* window_title,
	bool show,
	void* owner_window_handle)
{
	return BeginAsyncFileFolderDialog(
		file_dialog_handle,
		window_title,
		show,
		owner_window_handle,
		true,
		false,
		false,
		true);
}

bool ImGui::BeginAsyncSaveFolderDialog(
	t_imgui_async_file_dialog_handle* file_dialog_handle,
	const char* window_title,
	bool show,
	void* owner_window_handle)
{
	return BeginAsyncFileFolderDialog(
		file_dialog_handle,
		window_title,
		show,
		owner_window_handle,
		false,
		true,
		false,
		true);
}

void ImGui::EndAsyncFileDialog()
{
	ASSERT(current_file_dialog_handle != nullptr);
	s_imgui_async_file_dialog_handle*& async_file_dialog = *current_file_dialog_handle;
	ASSERT(async_file_dialog != nullptr);
	ASSERT(async_file_dialog->ready_to_dispose);

	tracked_free(async_file_dialog->filepath_widechar);
	tracked_free(async_file_dialog->filepath_multibyte);

	delete async_file_dialog;
	async_file_dialog = nullptr;
	current_file_dialog_handle = nullptr;
}


bool ImGui::AsyncFileDialogIsValid()
{
	ASSERT(current_file_dialog_handle != nullptr);
	ASSERT(*current_file_dialog_handle != nullptr);
	s_imgui_async_file_dialog_handle& async_file_dialog = **current_file_dialog_handle;
	ASSERT(async_file_dialog.ready_to_dispose);

	return !async_file_dialog.error && !async_file_dialog.user_cancelled;
}

bool ImGui::AsyncFileDialogIsError()
{
	ASSERT(current_file_dialog_handle != nullptr);
	ASSERT(*current_file_dialog_handle != nullptr);
	s_imgui_async_file_dialog_handle& async_file_dialog = **current_file_dialog_handle;
	ASSERT(async_file_dialog.ready_to_dispose);

	return async_file_dialog.error;
}

bool ImGui::AsyncFileDialogUserCancelled()
{
	ASSERT(current_file_dialog_handle != nullptr);
	ASSERT(*current_file_dialog_handle != nullptr);
	s_imgui_async_file_dialog_handle& async_file_dialog = **current_file_dialog_handle;
	ASSERT(async_file_dialog.ready_to_dispose);

	return async_file_dialog.user_cancelled;
}

const wchar_t* ImGui::AsyncFileDialogGetFilepathWideChar()
{
	ASSERT(current_file_dialog_handle != nullptr);
	ASSERT(*current_file_dialog_handle != nullptr);
	s_imgui_async_file_dialog_handle& async_file_dialog = **current_file_dialog_handle;
	ASSERT(async_file_dialog.ready_to_dispose);

	return async_file_dialog.filepath_widechar;
}

const char* ImGui::AsyncFileDialogGetFilepathMultiByte()
{
	ASSERT(current_file_dialog_handle != nullptr);
	ASSERT(*current_file_dialog_handle != nullptr);
	s_imgui_async_file_dialog_handle& async_file_dialog = **current_file_dialog_handle;
	ASSERT(async_file_dialog.ready_to_dispose);

	return async_file_dialog.filepath_multibyte;
}
