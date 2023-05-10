#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "windows.h"
#include "addresses_table.h"
#include "player.h"
#include "minus.h"


extern GameAddressTable* addrTable = new GameAddressTableTSF();
extern PlayerPropertiesOffsetsTable* playOffstTable = new PlayerPropertiesOffsetsTableTSF();

bool init() 
{
    addrTable = new GameAddressTableTSF();
    playOffstTable = new PlayerPropertiesOffsetsTableTSF();
    return true;
}

/// <summary>This function is called on startup to setup jump points</summary>
/// <returns>returns true if successful</returns>
bool patchInitialize()
{
    MessageBoxA(NULL, "DLL STARTED!", "DLL STARTED", MB_OK);
    return true;
}