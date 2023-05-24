#include "pch.h"
#include "stdint.h"
#include "jjvariables.h"
#include "addresses_table.h"


namespace JJVariables
{
    extern HWND* pGameWindow = 0;
    extern HMENU* pGameMenuBar = 0;
    extern char *GameMode = 0;
    extern int  *MaxScore = 0;
    extern const double SOME_CONST;

    extern bool init(GameAddressTable& gTbl)
    {
        //Assign addresses
        pGameWindow = (HWND*)gTbl.GAME_WINDOW_POINTER;
        pGameMenuBar = (HMENU*)gTbl.GAME_MENU_BAR_POINTER;
        GameMode = (char*)gTbl.GAME_MODE;
        MaxScore = (int*)gTbl.MAX_SCORE;
        return true;
    }
}