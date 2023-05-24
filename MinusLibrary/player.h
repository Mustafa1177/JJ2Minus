#pragma once

#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "addresses_table.h"

class Player {       
public: 

    int* health;
    char* name[24];
    int myNum;
  
    void init(int playerID, GameAddressTable& gTbl, PlayerPropertiesOffsetsTable& pTbl);

private:
    int playerID = 0;
    int playerHandle;
};
