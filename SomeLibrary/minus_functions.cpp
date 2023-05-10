//General function like chat
#include "pch.h"
#include "jjvariables.h"

bool RemoveMenuBar() 
{
	HWND hGameWindow = *JJVariables::pGameWindow;
	return SetMenu(hGameWindow, NULL);
}

void SendMessage() 
{

}