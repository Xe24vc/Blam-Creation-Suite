#pragma once

#if BCS_USE_SHARED_LIBRARIES
#ifdef BCS_DEBUG_API
#undef BCS_DEBUG_API
#endif
#define BCS_DEBUG_API __declspec(dllexport)
#endif
