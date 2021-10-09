#pragma once

#define BCS_DEBUG_API_EXPORT __declspec(dllexport)
#define BCS_DEBUG_API_IMPORT __declspec(dllimport)

#if _DEBUG
#ifndef BCS_DEBUG_API
#define BCS_DEBUG_API BCS_DEBUG_API_IMPORT
#endif
#else
#ifndef BCS_DEBUG_API
#define BCS_DEBUG_API
#endif
#endif