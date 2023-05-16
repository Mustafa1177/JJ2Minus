#pragma once

#define IDM_OPEN_INI   16325
#define IDM_RELOAD_INI 16326
#define IDM_TEST       16327

#include <stdio.h>

typedef void (*MenuItemHandler)();

LRESULT CALLBACK MyWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL HookWindowProcedure(HWND hWnd);

void menuHandler();
void killMenu();