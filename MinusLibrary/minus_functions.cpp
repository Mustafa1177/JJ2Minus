//General function like chat
#include "pch.h"
#include "jjvariables.h"
#include "minus.h"

using namespace Minus;

typedef void JJ2SendChatMessageFunction(char*);

bool RemoveMenuBar() 
{
	HWND hGameWindow = *JJVariables::pGameWindow;
	return SetMenu(hGameWindow, NULL);
}

void SendChatMessage(char* msg)
{
	void (*function)(char*);
	function = (JJ2SendChatMessageFunction*)funcAddrTable->SEND_MESSAGE;
	function(msg);
}