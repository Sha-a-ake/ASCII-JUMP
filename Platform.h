#ifndef __PLATFORM__
#define __PLATFORM__

#include <stdbool.h>
#include "Player.h"
#include "Platform.h"

#define PLATFORM_WIDTH 11

typedef struct a
{
    int x;
    int y;
    bool dead;
    
} platform;


platform new_platform(int x, int y);


// Platform left side
int plnkls(platform plnk);

// Platform right side
int plnkrs(platform plnk);

// Plank height
int plnkh(platform plnk);

// Plank-player collision
bool plnkcln(platform plnk, player plyr);

#endif
