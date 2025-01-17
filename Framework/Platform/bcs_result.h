#pragma once

enum BCS_RESULT
{
	BCS_E_DATA_ALREADY_MAPPED = -11,
	BCS_E_DATA_NOT_MAPPED = -10,
	BCS_E_MISSING_RESOURCE = -9,
	BCS_E_FATAL = -8,
	BCS_E_OUT_OF_RANGE = -7,
	BCS_E_NOT_FOUND = -6,
	BCS_E_UNSUPPORTED = -5,
	BCS_E_NOT_IMPLEMENTED = -4,
	BCS_E_UNEXPECTED = -3,
	BCS_E_INVALID_ARGUMENT = -2,
	BCS_E_FAIL = -1,
	BCS_S_OK = 0,
	BCS_S_SEARCH_STOP = 1,
};

BCS_RESULT bcs_result_to_string_mb(BCS_RESULT bcs_result, const char*& bcs_result_string);
BCS_RESULT bcs_result_to_string_wc(BCS_RESULT bcs_result, const wchar_t*& bcs_result_string);
