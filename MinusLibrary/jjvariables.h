#pragma once

#include "addresses_table.h"
namespace JJVariables
{
    extern HWND *  pGameWindow;
    extern HMENU*  pGameMenuBar;
    extern char *  GameMode;
    extern int  *  MaxScore;
    extern const double SOME_CONST;

    extern bool init(GameAddressTable& gTbl);
}
