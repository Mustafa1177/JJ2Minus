//This file contains functions that will change the behaviour of the game code
#include "pch.h"
#include "minus.h"

namespace MinusFixes
{
	void ChangeDefaultNetUpdateRate(char internetDelay = 70, char lanDelay = 42) {
		char* netDefInternetUpdateDelay = (char*)addrTable->NET_DEF_INTERNET_UPDATE_DELAY;
		*netDefInternetUpdateDelay = internetDelay;
	}
}