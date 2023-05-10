// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include "windows.h"
#include "minus.h"
#include "addresses_table.h"
#include "player.h"
#include "minus_fixes.h"

DWORD WINAPI MainThread(LPVOID param)
{
	GameAddressTable* addrTable = new GameAddressTableTSF();
	PlayerPropertiesOffsetsTable* playOffstTable = new PlayerPropertiesOffsetsTableTSF();
	Player player1;
	player1.init(0, *addrTable, *playOffstTable);

	while (true) {
		if (GetAsyncKeyState(VK_F2) & 0x80000) {
			//MessageBoxA(NULL, "F6 pressed!", "Minus", MB_OK);
			int* player1Hp;
			player1Hp = (int*)0x005C853E;
			//*player1Hp = 0;
			*player1.health = 0;
			MinusFixes::ChangeDefaultNetUpdateRate(10, 10);
		}
		Sleep(8);
	}
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		patchInitialize(); //call minus.cpp
		CreateThread(0, 0, MainThread, hModule, 0, 0);
		std::cout << "haha3" << std::endl;

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



