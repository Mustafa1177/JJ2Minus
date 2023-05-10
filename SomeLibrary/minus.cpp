#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "windows.h"
#include "addresses_table.h"
#include "player.h"
#include "minus.h"
#include "minus_fixes.h"

namespace Minus 
{
	extern GameAddressTable* addrTable = new GameAddressTableTSF();
	extern PlayerPropertiesOffsetsTable* playOffstTable = new PlayerPropertiesOffsetsTableTSF();
	extern HANDLE hCurrentProcess = 0;


	void MemoryWrite(LPVOID address, unsigned char data)
	{
		DWORD dataSize = sizeof(data);
		if (WriteProcessMemory(hCurrentProcess, address, &data, dataSize, NULL)) // newdatasize = 4 byte
		{
			//MessageBoxA(NULL, "WriteProcessMemory worked.", "Success", MB_OK + MB_ICONINFORMATION);
		}
		else
		{
			MessageBoxA(NULL, "Error cannot WriteProcessMemory!", "Error", MB_OK + MB_ICONERROR);
		}
	}
	
	bool init()
	{
		DWORD proccess_ID = GetCurrentProcessId();
		hCurrentProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proccess_ID);
		addrTable = new GameAddressTableTSF();
		playOffstTable = new PlayerPropertiesOffsetsTableTSF();
		return patchInitialize();
	}
	
	bool patchInitialize()
	{
		MessageBoxA(NULL, "DLL STARTED!", "DLL STARTED", MB_OK);
		MinusFixes::ChangeDefaultNetUpdateRate(28, 14);
		return true;
	}
}