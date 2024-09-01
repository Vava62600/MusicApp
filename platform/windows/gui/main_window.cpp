#include <windows.h>
#include "main_window.h"
#include "backend/server_manager.h"

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
void AddControls(HWND);

HMENU hMenu;
HWND hwnd;

// Fonction principale
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"MusicAppWindow";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) {
        return -1;
    }

    hwnd = CreateWindowW(L"MusicAppWindow", L"MusicApp", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 800, 600, NULL, NULL, NULL, NULL);
    MSG msg = {0};

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Fonction de traitement des messages Windows
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_COMMAND:
        switch (wp) {
        case 1:  // Cas du menu de changement de rôle
            ServerManager::switchToClientMode();
            break;
        case 2:
            ServerManager::switchToServerMode();
            break;
        }
        break;
    case WM_CREATE:
        AddMenus(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}

// Fonction pour ajouter des menus
void AddMenus(HWND hWnd) {
    hMenu = CreateMenu();
    AppendMenu(hMenu, MF_STRING, 1, "Switch to Client Mode");
    AppendMenu(hMenu, MF_STRING, 2, "Switch to Server Mode");
    SetMenu(hWnd, hMenu);
}
