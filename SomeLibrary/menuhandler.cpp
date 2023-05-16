#include "pch.h"
#include "menuhandler.h"
#include "jjvariables.h"

#include "stdio.h"
#include <windows.h>
#include "detours/src/detours.h"

#define IDM_CUSTOM_MENU_ITEM   16325
#define IDM_CUSTOM_MENU_ITEM_2 16326

typedef void (*MenuItemHandler)();
WNDPROC g_pOriginalWndProc = NULL;

LRESULT CALLBACK MyWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_COMMAND)
    {
        WORD menuItemID = LOWORD(wParam);

        printf("How about we go BOWLING?\n");

        if (menuItemID == IDM_CUSTOM_MENU_ITEM)
        {
            printf("Cousin, we are family!\n");
            return 0;
        }

        if (menuItemID == IDM_CUSTOM_MENU_ITEM_2)
        {
            printf("Of course I should be spending time with you.\n");
            return 0;
        }
    }

    return CallWindowProc(g_pOriginalWndProc, hWnd, uMsg, wParam, lParam);
}

BOOL HookWindowProcedure(HWND hWnd)
{
    g_pOriginalWndProc = (WNDPROC)GetWindowLongPtr(hWnd, GWLP_WNDPROC);

    if (g_pOriginalWndProc == NULL)
    {
        printf("[ERROR] [MENU] Failed to get the original window procedure!");
        return FALSE;
    }

    if (!SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)MyWndProc))
    {
        printf("[ERROR] [MENU] Failed to set the custom window procedure!");
        return FALSE;
    }

    return TRUE;
}

bool hooked = false;

void menuHandler()
{
    HMENU hMenu = CreateMenu();
    HMENU hSubMenu = CreatePopupMenu();
    AppendMenu(hSubMenu, MF_STRING, IDM_CUSTOM_MENU_ITEM, "Test item 1");
    AppendMenu(hSubMenu, MF_STRING, IDM_CUSTOM_MENU_ITEM_2, "Test item 2");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu, "Minus");

    HWND hWnd = *JJVariables::pGameWindow;
    SetMenu(hWnd, hMenu);

    if (!hooked && !HookWindowProcedure(hWnd))
    {
        printf("fucked up\n");
        return;
    }

    printf("yippee\n");

    hooked = true;
}

void killMenu()
{
    if (hooked) {
        SetWindowLongPtr(*JJVariables::pGameWindow, GWLP_WNDPROC, (LONG_PTR)g_pOriginalWndProc);
        hooked = false;
    }
}