#include "pch.h"
#include "addresses_table.h"


ADDRESSES_TABLE_H::GameAddressTableTSF;

//v1.24 (TSF) section
GameAddressTableTSF::GameAddressTableTSF()
{
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

//v1.23 section
GameAddressTableV23::GameAddressTableV23()
{
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




//////////////////////////////////////////////
/* OLD IMPLEMENTATION

struct GameAddressTable
{ //This is an abstract
	virtual void f() = 0;  // pure virtual

public:
	int PLAYER_STRUCT_SIZE;
	DWORD PLAYERS_ARRAY;
	DWORD MAX_SCORE;
	DWORD SERVER_NAME;
};

struct PlayerOffsetsTable
{ //This is an abstract
	virtual void f() = 0;  // pure virtual

public:
	int WEAPONS_COUNT = 10;
	DWORD Health;
	DWORD POS_X;
	DWORD POS_Y;
};


struct GameAddressTableTSF : GameAddressTable
{
	void f() override {}   // non-pure virtual
	virtual void g();      // non-pure virtual

public:
	GameAddressTableTSF() {
		PLAYERS_ARRAY = 0x005C8500;
		MAX_SCORE = 0x005F37F0;
		SERVER_NAME = 0x0061E7A8;

		PLAYER_STRUCT_SIZE = 1444;
	}

}; // "GameAddressTableTSF" is non-abstract

struct GameAddressTable23 : GameAddressTable
{
	void f() override {}   // non-pure virtual
	virtual void g();      // non-pure virtual

public:
	GameAddressTable23() {
		MAX_SCORE = 0x005F37F0;

	}
}; // "GameAddressTable23" is non-abstract
*/