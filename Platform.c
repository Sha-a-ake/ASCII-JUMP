#include "Platform.h"
#include "Player.h"
#include "stdbool.h"

int plnkls(platform plnk)
{
    return plnk.x;
}

int plnkrs(platform plnk)
{
    return plnk.x + PLATFORM_WIDTH - 1;
}

int plnkh(platform plnk)
{
    return plnk.y;
}


bool plnkcln(platform plnk, player plyr)
{
    if ((plnkh(plnk) == plyrbh(plyr)) && (plnkls(plnk) <= plyrrs(plyr)) && (plnkrs(plnk) >= plyrls(plyr)))
        return true;
    else
        return false;
}

