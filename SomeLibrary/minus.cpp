#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "windows.h"
#include <cstdio>

#include "addresses_table.h"
#include "jjvariables.h"
#include "player.h"
#include "minus.h"
#include "minus_fixes.h"
#include "minus_functions.h"
#include "menuhandler.h"

namespace Minus 
{
	extern GameAddressTable* addrTable = new GameAddressTableTSF();
	extern PlayerPropertiesOffsetsTable* playOffstTable = new PlayerPropertiesOffsetsTableTSF();
	extern GameFunctionsAddressTable* funcAddrTable = new GameFunctionsAddressTableTSF();
	extern HANDLE hCurrentProcess = 0;
	extern DWORD plusBaseAddress = 0;

	void MemoryWrite(LPVOID address, unsigned char data)
	{
		DWORD dataSize = sizeof(data);

		if (WriteProcessMemory(hCurrentProcess, address, &data, dataSize, NULL)) // newdatasize = 4 byte
		{
			// printf("[INFO] WriteProcessMemory worked!\n");
		}
		else
		{
			printf("[ERROR] WriteProcessMemory failed!\n");
		}
	}
	
	bool init()
	{
		bool res = true;
		DWORD proccess_ID = GetCurrentProcessId();

		AllocConsole();
		FILE* f = new FILE();
		freopen_s(&f, "CONOUT$", "w", stdout);

		printf("[INFO] Running!\n");

		hCurrentProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, proccess_ID);
		
		if (!hCurrentProcess)
			printf("[ERROR] OpenProcess failed!\n");
		
		addrTable = new GameAddressTableTSF();
		playOffstTable = new PlayerPropertiesOffsetsTableTSF();
		funcAddrTable = new GameFunctionsAddressTableTSF();
		
		res = (!JJVariables::init(*addrTable)) || (!patchInitialize());

		CloseHandle(hCurrentProcess);

		return res;
	}
	
	bool patchInitialize()
	{
		printf("[INFO] The minus DLL has started!");

		MinusFixes::ChangeDefaultNetUpdateRate(28, 14);

		return true;
	}

	void Learning() 
	{
		char msg[] = "Hello World!\0";

		SendChatMessage(msg);

		menuHandler();
	}
}