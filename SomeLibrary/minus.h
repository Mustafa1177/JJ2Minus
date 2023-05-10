#ifndef MINUS_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define MINUS_H

#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "windows.h"
#include "addresses_table.h"

namespace Minus
{
	extern GameAddressTable* addrTable;
	extern PlayerPropertiesOffsetsTable* playOffstTable;
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

	void Learning();
}
#endif