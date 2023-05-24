#include "pch.h"
#include "menuhandler.h"
#include "jjvariables.h"

#include <cstdlib>
#include <windows.h>
#include "libs/detours/detours.h"
#include "minus.h"

typedef void (*MenuItemHandler)();
WNDPROC g_pOriginalWndProc = NULL;

bool hooked = false;

// test checkbox
bool checkboxOn = false;

LRESULT CALLBACK MyWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_COMMAND)
    {
        WORD menuItemID = LOWORD(wParam);

        DrawMenuBar(*JJVariables::pGameWindow);

        if (menuItemID == IDM_OPEN_INI)
        {
            std::system("start /B notepad.exe minus.ini");
            return 0;
        }

        if (menuItemID == IDM_RELOAD_INI)
        {
            reloadConfig();
            return 0;
        }

        if (menuItemID == IDM_TEST)
        {
            checkboxOn = !checkboxOn;
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


void menuHandler()
{
    HMENU hMenu = CreateMenu();
    HMENU hSubMenu = CreatePopupMenu();
    AppendMenu(hSubMenu, MF_STRING, IDM_OPEN_INI, "Open minus.ini");
    AppendMenu(hSubMenu, MF_STRING, IDM_RELOAD_INI, "Reload minus.ini");
    AppendMenu(hSubMenu, MF_STRING | (checkboxOn ? MF_CHECKED : 0), IDM_TEST, "Test item 3");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSubMenu, "Minus");

    HWND hWnd = *JJVariables::pGameWindow;
    SetMenu(hWnd, hMenu);

    if (!hooked && !HookWindowProcedure(hWnd))
    {
        printf("[ERROR] [MENU] Failed to hook the window procedure\n");
        return;
    }

    printf("[INFO] [MENU] Window procedure got hooked sucessfully!\n");

    hooked = true;

    DrawMenuBar(*JJVariables::pGameWindow);
}

void killMenu()
{
    if (hooked) {
        SetWindowLongPtr(*JJVariables::pGameWindow, GWLP_WNDPROC, (LONG_PTR)g_pOriginalWndProc);
        hooked = false;
    }
}
