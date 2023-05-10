#include "pch.h"
#include "Player.h"
#include "addresses_table.h"


void Player::init(int playerID, GameAddressTable& gTbl, PlayerPropertiesOffsetsTable& pTbl)
{
    //Find player in game module memory
    DWORD addr;
    this->playerID = playerID;
    addr = gTbl.PLAYERS_ARRAY + playerID * gTbl.PLAYER_STRUCT_SIZE;
    this->playerHandle = addr;

    //Assign addresses
    health = (int*)(addr + pTbl.HEALTH);
    //name = (int*)addr + pTbl.NAME;

}

