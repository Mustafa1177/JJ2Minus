#include "pch.h"
#include "drawing.h"
#include <iostream>
#include <Windows.h>
#include "jjvariables.h"

HWND hwnd;
HDC dc;

void Drawing_InitDrawing() {
    hwnd = *JJVariables::pGameWindow;
    dc = GetDC(hwnd);
}

void Drawing_SetDrawColor(int r, int g, int b) {
    SetDCBrushColor(dc, RGB(r, g, b));
}

void Drawing_DrawText(const wchar_t* text, int x, int y, int w, int h) {
    RECT rect = { x, y, x + w, y + h };
    DrawTextW(dc, text, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void Drawing_DrawRectangle(int x, int y, int w, int h) {
    Rectangle(dc, x, y, x + w, y + h);
}

void Drawing_ReleaseDrawing() {
    ReleaseDC(hwnd, dc);
}
