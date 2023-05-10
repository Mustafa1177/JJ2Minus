#include "pch.h"
#include "stdint.h"
#include "jjvariables.h"
#include "addresses_table.h"


namespace JJVariables
{
    extern char *GameMode = 0;
    extern int  *MaxScore = 0;
    extern const double SOME_CONST;

    extern bool init(GameAddressTable& gTbl)
    {
        //Assign addresses
        GameMode = (char*)gTbl.GAME_MODE;
        MaxScore = (int*)gTbl.MAX_SCORE;
        return true;
    }
}