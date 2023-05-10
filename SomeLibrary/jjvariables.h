#ifndef JJVARIABLES_H
#define JJVARIABLES_H
#include "addresses_table.h"
namespace JJVariables
{
    // since the actual variables are inside a namespace, the forward declarations need to be inside a namespace as well
    extern char  *GameMode;
    extern int  *MaxScore;
    extern const double SOME_CONST;

    extern bool init(GameAddressTable& gTbl);
}

#endif

