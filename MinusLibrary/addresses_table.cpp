#include "pch.h"
#include "addresses_table.h"

//v1.24 (TSF) section
GameAddressTableTSF::GameAddressTableTSF()
{
	GAME_WINDOW_POINTER = 0x004F33FC;
	GAME_MENU_BAR_POINTER = 0x004F341C;
	PLAYERS_ARRAY = 0x005C8500;
	MAX_SCORE = 0x005F37F0;
	GAME_MODE = 0x005C8188;
	SERVER_NAME = 0x0061E7A8;
	GAME_TICKS = 0x0;
	NET_DEF_INTERNET_UPDATE_DELAY = 0x00486295;
	PLAYER_STRUCT_SIZE = 1444;
}

PlayerPropertiesOffsetsTableTSF::PlayerPropertiesOffsetsTableTSF()
{
	HEALTH = 62; // 0x3E
	NAME = 72;

}

GameFunctionsAddressTableTSF::GameFunctionsAddressTableTSF() 
{
	SEND_MESSAGE = 0x4833A0;
}

//v1.23 section
GameAddressTableV23::GameAddressTableV23()
{
	GAME_WINDOW_POINTER = 0x004F8E1C;
	GAME_MENU_BAR_POINTER = 0x004F8E44;
	PLAYERS_ARRAY = 0x0;
	MAX_SCORE = 0x005D01D0;
	GAME_MODE = 0x005A4B68;
	SERVER_NAME = 0x005FB188;
	GAME_TICKS = 0x0058A5A0;
	PLAYER_STRUCT_SIZE = 1444;
}

PlayerPropertiesOffsetsTableV23::PlayerPropertiesOffsetsTableV23()
{

}

GameFunctionsAddressTableV23::GameFunctionsAddressTableV23()
{
	SEND_MESSAGE = 0x0;
}
