#pragma once

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers
#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_dx9.h"
#include "../imgui/imgui_impl_win32.h"

//Own components headers
#include "../header/menuLogic/MenuLogic.h"
#include "../header/fonts/Fonts.h"
#include "../header/menubar/MenuBar.h"
#include "../header/filebrowser/imfilebrowser.h"
//Forward declarations

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
bool CreateDeviceD3D(HWND& hWnd);
void CleanupDeviceD3D();
void ResetDevice();

static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};
static LPDIRECT3D9              g_pD3D = NULL;

class Application {
public:

    static void run();

private:
    void Imain();
    void Iinit();
    void Irender();
    void Ideinit();

    bool Enabled = true;

    ImVec4 clear_color;

    WNDCLASSEX wc;
    HWND Window = nullptr;
};

