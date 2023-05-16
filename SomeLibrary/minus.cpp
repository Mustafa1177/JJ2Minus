#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "minus.h"
#include "libs/inireader/INIreader.hpp"

std::string getCCWD() {
	char cwd[1024];

	if (_getcwd(cwd, sizeof(cwd)) != nullptr) {
		return std::string(cwd);
	}

	return ".";
}

extern INIReader config(getCCWD() + "/minus.ini");

void reloadConfig() {
	MinusFixes::ChangeDefaultNetUpdateRate(
		static_cast<char>(config.GetInteger("Network", "NetUpdateRate", 28)),
		static_cast<char>(config.GetInteger("Network", "LanUpdateRate", 14))
	);
}

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
		
		reloadConfig();

		bool res = (!JJVariables::init(*addrTable)) || (!patchInitialize());

		CloseHandle(hCurrentProcess);

		return res;
	}
	
	bool patchInitialize()
	{
		printf("[INFO] The minus DLL has started!\n");

		return true;
	}

	void Learning() 
	{
		// char msg[] = "Hello World!\0";

		// SendChatMessage(msg);
		menuHandler();
	}
}