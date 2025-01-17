#pragma once

enum e_clipboard_data_type
{
	_clipboard_data_type_text
};

BCS_DEBUG_API BCS_RESULT clipboard_set_data(e_clipboard_data_type data_type, const void* data, unsigned long size);
BCS_DEBUG_API BCS_RESULT clipboard_set_text(const char* text);
