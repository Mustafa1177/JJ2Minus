// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include "windows.h"
#include "minus.h"
#include "addresses_table.h"
#include "player.h"
#include "minus_fixes.h"
#include "minus_functions.h"
#include "jjvariables.h"

DWORD WINAPI MainThread(LPVOID param)
{
	GameAddressTable* addrTable = new GameAddressTableTSF();
	PlayerPropertiesOffsetsTable* playOffstTable = new PlayerPropertiesOffsetsTableTSF();
	Player player1;
	player1.init(0, *addrTable, *playOffstTable);

	bool wasKeyPressed = false;

	while (true) {
		if (GetAsyncKeyState(VK_F2) & 0x8000) {
			if (!wasKeyPressed) {
				int* player1Hp;
				player1Hp = (int*)0x005C853E;
				//*player1Hp = 0;
				//*player1.health = 0;
			
				Minus::Learning();
			
				printf("[INFO] F2 pressed!\n");
				
				wasKeyPressed = true;
			}
		} else {
			wasKeyPressed = false;
		}

		Sleep(8);
	}
	
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Minus::init(); //call minus.cpp
		CreateThread(0, 0, MainThread, hModule, 0, 0);
		printf("\n[INFO] Minus has fully loaded!\n");

		/*int* player1Hp;
		player1Hp = (int*)0x005C853E;
		*player1Hp = 0;*/
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}



