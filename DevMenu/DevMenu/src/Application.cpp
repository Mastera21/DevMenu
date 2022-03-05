#include "../header/Application.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

void Application::Iinit() {
    wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, L"External Menu Base", NULL };
    ::RegisterClassEx(&wc);
    Window = ::CreateWindow(wc.lpszClassName, L"External Menu Base", WS_POPUP, NULL, NULL, 5, 5, NULL, NULL, wc.hInstance, NULL);

    if (!CreateDeviceD3D(Window)) {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return;
    }

    ::ShowWindow(Window, SW_HIDE);
    ::UpdateWindow(Window);

    ImGui::CreateContext();
    //Fonts
    Fonts::Init();

    ImGui_ImplWin32_Init(Window);
    ImGui_ImplDX9_Init(g_pd3dDevice);
}
void Application::Imain() {
    Iinit();
    clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    //Set file filter
    ImGui::FileBrowser fileDialog;
    fileDialog.SetTitle("Files ...");
    fileDialog.SetTypeFilters({".cpp", ".h", ".jpg"});

    ImGuiStyle& style = ImGui::GetStyle();

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (Enabled){
        while (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)){
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            if (msg.message == WM_QUIT) {
                Enabled = !Enabled;
            }
        }

        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        MenuLogic::Style(style);

        //Update every frame
        {
            ImGui::Begin("DevMenu", &Enabled, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_AlwaysUseWindowPadding);
        
            //Menu bar
            MenuBar::Render(clear_color, style, Enabled);

            //Main logic render
            MenuLogic::Render(fileDialog);
    
            ImGui::End();
        }

        fileDialog.Display();

        if (fileDialog.HasSelected()){
            std::cout << "Selected filename" << fileDialog.GetSelected().string() << std::endl;
            fileDialog.ClearSelected();
        }

        ImGui::EndFrame();
        // Rendering
        Irender();
    }
    Ideinit();
}
void Application::run() {
    Application app;
    app.Imain();
}
void Application::Irender() {
    D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x * clear_color.w * 255.0f), (int)(clear_color.y * clear_color.w * 255.0f), (int)(clear_color.z * clear_color.w * 255.0f), (int)(clear_color.w * 255.0f));
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
    if (g_pd3dDevice->BeginScene() >= 0) {
        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
        g_pd3dDevice->EndScene();
    }

    HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
    if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
        ResetDevice();
    }
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
}
void Application::Ideinit() {
    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(Window);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);
}
// Helper functions
bool CreateDeviceD3D(HWND& hWnd){
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION))) {
        return false;
    }

    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    if (FAILED (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice))) {
        return false;
    }

    // Turn off culling
    g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

    // Turn off D3D lighting
    g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

    // Turn on the zbuffer
    g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

    return true;
}
void CleanupDeviceD3D() {
    if (g_pd3dDevice) {
        g_pd3dDevice->Release(); g_pd3dDevice = NULL;
    }
    if (g_pD3D) {
        g_pD3D->Release(); g_pD3D = NULL;
    }
}
void ResetDevice(){
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT Result = g_pd3dDevice->Reset(&g_d3dpp);
    if (Result == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg) {
    case WM_SIZE:
        if (g_pd3dDevice != 0 && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
