#pragma once

#define __IMGUI_ASYNC_FILE_DIALOG_IMPL__

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <hidusage.h>
#include <shellscalingapi.h>

#include <intrin.h>

#include <dxgi.h>
#include <dxgi1_6.h>
#include <d3d11.h>
#include <d3d11_4.h>

#include <dxgi1_6.h>
#include <dxgidebug.h>
#include <d3d12.h>
#include <directx\d3dx12.h>

#define PLATFORM_ENABLE_THROW_NEW
#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <Shared\shared-public-pch.h>

#include <Platform/platform-exports-pch.h>

#include "graphicslib-public-pch.h"
#include "D3D11/d3d11-private-pch.h"
#include "D3D12/d3d12-private-pch.h"
#include "Windows/windows-private-pch.h"
#include "ThirdParty/thirdparty-public-pch.h"

#include "Scenes\imgui_viewport_render_context.h"
#include "Scenes\window_render_context.h"

#include <DirectXMath.h>
