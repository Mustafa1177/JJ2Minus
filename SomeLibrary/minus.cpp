#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "windows.h"
#include "addresses_table.h"
#include "jjvariables.h"
#include "player.h"
#include "minus.h"
#include "minus_fixes.h"
#include "minus_functions.h"

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
			//MessageBoxA(NULL, "WriteProcessMemory worked.", "Success", MB_OK + MB_ICONINFORMATION);
		}
		else
		{
			MessageBoxA(NULL, "Error cannot WriteProcessMemory!", "Error", MB_OK + MB_ICONERROR);
		}
	}
	
	bool init()
	{
		bool res = true;
		DWORD proccess_ID = GetCurrentProcessId();
		hCurrentProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, proccess_ID);
		if(!hCurrentProcess)
			MessageBoxA(NULL, "Error cannot OpenProcess!", "Error", MB_OK + MB_ICONERROR);
		addrTable = new GameAddressTableTSF();
		playOffstTable = new PlayerPropertiesOffsetsTableTSF();
		funcAddrTable = new GameFunctionsAddressTableTSF();
		//Learning();
		if (!JJVariables::init(*addrTable))
			res = false;
		if (!patchInitialize())
			res = false;
		CloseHandle(hCurrentProcess);
		return res;
	}
	
	bool patchInitialize()
	{
		MessageBoxA(NULL, "DLL STARTED!", "DLL STARTED", MB_OK);
		MinusFixes::ChangeDefaultNetUpdateRate(28, 14);
		return true;
	}

	void Learning() 
	{
		char msg[] = "Hello World!\0";

		SendChatMessage(msg);

		HWND hGameWindow = *JJVariables::pGameWindow;
		HMENU hGameMenuBar = *JJVariables::pGameMenuBar;
		
		//CreatePopupMenu();
		AppendMenuA(hGameMenuBar, 0, 0, "Minus Test");
		DrawMenuBar(hGameWindow);
		//SetMenu(hGameWindow, NULL);
	}
}