#pragma once

#include <Windows.h>

void Drawing_InitDrawing();
void Drawing_SetDrawColor(int r, int g, int b);
void Drawing_DrawText(const wchar_t* text, int x, int y, int w, int h);
void Drawing_DrawRectangle(int x, int y, int w, int h);
void Drawing_ReleaseDrawing();
