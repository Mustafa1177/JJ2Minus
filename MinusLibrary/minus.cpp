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

// may have a memory leak, watch out :)
const char* const DWORDToCChar(DWORD value) {
	std::string str = std::to_string(value);
	char* charArray = new char[str.length() + 1];
	strcpy_s(charArray, str.length() + 1, str.c_str());
	const char* const result = charArray;
	return result;
}

std::string DWORDErrorMessageToString(DWORD errorCode) {
	LPSTR messageBuffer = nullptr;
	DWORD size = FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		nullptr,
		errorCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		reinterpret_cast<LPSTR>(&messageBuffer),
		0,
		nullptr
	);

	std::string errorMessage(messageBuffer, size);

	LocalFree(messageBuffer);

	// Remove trailing newline character
	if (!errorMessage.empty() && errorMessage.back() == '\n') {
		errorMessage.pop_back();
	}

	return errorMessage;
}

extern INIReader config(getCCWD() + "/minus.ini");

void reloadConfig() {
	MinusFixes::ChangeDefaultNetUpdateRate(
		static_cast<char>(config.GetInteger("Network", "NetUpdateRate", 70)),
		static_cast<char>(config.GetInteger("Network", "LanUpdateRate", 42))
	);
}

namespace Minus
{
	extern GameAddressTable* addrTable = new GameAddressTableTSF();
	extern PlayerPropertiesOffsetsTable* playOffstTable = new PlayerPropertiesOffsetsTableTSF();
	extern GameFunctionsAddressTable* funcAddrTable = new GameFunctionsAddressTableTSF();
	extern HANDLE hCurrentProcess = 0;
	extern DWORD plusBaseAddress = 0;

	void closeApplication()
	{
		CloseHandle(hCurrentProcess);
	}

	void MemoryWrite(LPVOID address, unsigned char data)
	{
		DWORD dataSize = sizeof(data);

		if (WriteProcessMemory(hCurrentProcess, address, &data, dataSize, NULL)) // newdatasize = 4 byte
		{
			// printf("[INFO] WriteProcessMemory worked!\n");
		}
		else
		{
			_Post_equals_last_error_ DWORD e = GetLastError();

			printf(("[ERROR] WriteProcessMemory failed, error message: '" + DWORDErrorMessageToString(e)  + "'\n").c_str());
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