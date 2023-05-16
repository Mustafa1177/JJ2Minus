#pragma once

#define IDM_CUSTOM_MENU_ITEM   16325
#define IDM_CUSTOM_MENU_ITEM_2 16326

typedef void (*MenuItemHandler)();

LRESULT CALLBACK MyWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL HookWindowProcedure(HWND hWnd);

void menuHandler();
void killMenu();
