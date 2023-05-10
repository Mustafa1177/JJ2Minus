//General function like chat
#include "pch.h"
#include "jjvariables.h"
#include "minus.h"

using namespace Minus;

bool RemoveMenuBar() 
{
	HWND hGameWindow = *JJVariables::pGameWindow;
	return SetMenu(hGameWindow, NULL);
}

void SendChatMessage(char* msg)
{
	void (*myfunc)(char*);
	myfunc = (void (*)(char*))funcAddrTable->SEND_MESSAGE;
	myfunc(msg);
}