#ifndef __PLATFORM__
#define __PLATFORM__

#include <stdbool.h>
#include "Player.h"
#include "Platform.h"

#define PLATFORM_WIDTH 5

typedef union a
{
    int x;
    int y;
} platform;


// Platform left side
int plnkls(platform plnk);

// Platform right side
int plnkrs(platform plnk);

// Plank height
int plnkh(platform plnk);

// Plank-player collision
bool plnkcls(platform plnk, player plyr);

#endif
