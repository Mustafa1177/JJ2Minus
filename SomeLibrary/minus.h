#ifndef MINUS_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define MINUS_H

#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "windows.h"
#include "addresses_table.h"

extern GameAddressTable* addrTable;
extern PlayerPropertiesOffsetsTable* playOffstTable;

bool init();

bool patchInitialize();

#endif