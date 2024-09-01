#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
void AddControls(HWND);

#endif // MAIN_WINDOW_H
