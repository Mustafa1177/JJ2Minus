// SomeClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier

typedef struct IUnknown IUnknown;

#include <iostream>
#include "SomeLibrary.h"
#include "windows.h"
#include <TlHelp32.h>


int getProcId(const wchar_t* target) {
	DWORD pID = 0;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	do {
		if (wcscmp(pe32.szExeFile, target) == 0)
		{
			CloseHandle(hSnapshot);
			pID = pe32.th32ProcessID;
			break;
		}

	} while (Process32Next(hSnapshot, &pe32));
	//CloseHandle(hSnapshot);
	return pID;
}

void injectDll(char* argv[]) {


}

int main(int argc, char* argv[])
{
	// Initialize a Fibonacci relation sequence.
	fibonacci_init(1, 1);
	// Write out the sequence values until overflow.
	do {
		std::cout << fibonacci_index() << ": "
			<< fibonacci_current() << std::endl;
	} while (fibonacci_next());
	// Report count of values written before overflow.
	std::cout << fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << std::endl;

	injectDll(argv);
	std::cout << "haha" << std::endl;




	const wchar_t* process = L"Jazz2.exe"; // name of the process to inject into 
	int pID = getProcId(process);

	char dll[] = "SomeLibrary.dll"; // name of the dll file to inject
	char dllPath[MAX_PATH] = { 0 }; // full path of the dll
	GetFullPathNameA(dll, MAX_PATH, dllPath, NULL);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID); //PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ
	LPVOID pszLibFileRemote = VirtualAllocEx(hProcess, NULL, strlen(dllPath) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	WriteProcessMemory(hProcess, pszLibFileRemote, dllPath, strlen(dllPath) + 1, NULL);
	HANDLE handleThread = CreateRemoteThread(hProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryA, pszLibFileRemote, NULL, NULL);

	WaitForSingleObject(handleThread, INFINITE);
	CloseHandle(handleThread);
	VirtualFreeEx(hProcess, dllPath, 0, MEM_RELEASE);
	CloseHandle(hProcess);


	while (true)
	{

	}
}