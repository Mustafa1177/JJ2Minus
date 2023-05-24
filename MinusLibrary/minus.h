#pragma once

#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <windows.h>
#include <direct.h>
#include <string>
#include <cstdio>

#include "jjvariables.h"
#include "player.h"
#include "minus_functions.h"
#include "menuhandler.h"
#include "addresses_table.h"
#include "minus_fixes.h"

std::string getCCWD();

void reloadConfig();

namespace Minus
{
	extern GameAddressTable* addrTable;
	extern PlayerPropertiesOffsetsTable* playOffstTable;
	extern GameFunctionsAddressTable* funcAddrTable;
	extern HANDLE hCurrentProcess;
	extern DWORD plusBaseAddress;
	
	/// <summary>Writes a byte to current process memory</summary>
	void MemoryWrite(LPVOID address, unsigned char data);

	/// <summary>This function is called on startup to initialize JJ2Minus</summary>
	/// <returns>returns true if successful</returns>
	bool init();

	/// <summary>This function is called on startup to setup jump points</summary>
	/// <returns>returns true if successful</returns>
	bool patchInitialize();

	/// <summary>This function is used for testing the main features</summary>
	void Learning();
}
