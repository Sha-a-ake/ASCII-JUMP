
#include <math.h>

#include "Player.h"

player new_player(float x, float y)
{
    player plyr;

    plyr.x_real = x;
    plyr.y_real= y;

    plyr.x = trunc(x);
    plyr.y = trunc(y);

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
