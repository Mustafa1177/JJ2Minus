//This file contains functions that will change the behaviour of the game code
#include "pch.h"
#include "minus_fixes.h"
#include "jjvariables.h"
#include "minus.h"
#include <stdio.h>
#include <string>

using namespace Minus;

namespace MinusFixes
{
	void ChangeDefaultNetUpdateRate(char internetDelay, char lanDelay) {
		char* netDefInternetUpdateDelay = (char*)addrTable->NET_DEF_INTERNET_UPDATE_DELAY;
		MemoryWrite((LPVOID)netDefInternetUpdateDelay, 10);
	}
}