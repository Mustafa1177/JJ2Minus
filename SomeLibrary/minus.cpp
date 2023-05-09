#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "windows.h"

/// <summary>This function is called on startup to setup jump points</summary>
/// <returns>returns true if successful</returns>
bool patchInitialize()
{
    MessageBoxA(NULL, "DLL STARTED!", "DLL STARTED", MB_OK);
    return true;
}