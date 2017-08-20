#include "Player.h"

player new_player(int x, int y)
{
    player plyr;

    plyr.x = x;
    plyr.y = y;

    return plyr;
}

int plyrls(player plyr)
{
    return plyr.x;
}

int plyrrs(player plyr)
{
    return plyr.x + PLAYER_WIDTH - 1;
}

int plyrth(player plyr)
{
    return plyr.y;
}

int plyrbh(player plyr)
{
    return plyr.y + PLAYER_HEIGHT - 1;
}
