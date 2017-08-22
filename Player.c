
#include <math.h>

#include "Player.h"
#include "Rendering.h"

player new_player(float x, float y, float Vy)
{
    player plyr;

    plyr.x_real = x;
    plyr.y_real= y;

    plyr.x = floor(x);
    plyr.y = floor(y);

    plyr.Vy = Vy;

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

int plyrvy(player plyr)
{
    return plyr.Vy;
}

player plyrmv(player p, float dx, float dy)
{
    player new_plyr = new_player(p.x_real + dx, p.y_real + dy, p.Vy);


    return new_plyr;
}

player plyrfall(player p)
{
    player new_plyr = new_player(p.x_real, p.y_real - p.Vy, p.Vy - GRAVITATION);

    if (p.y >= WINDOW_HEIGHT-4) 
        new_plyr.Vy = 1;

    if (plyrls(p) < 2)
        new_plyr.x_real = 2;

    if (plyrrs(p) > WINDOW_WIDTH - 2)
        new_plyr.x_real = WINDOW_WIDTH - PLAYER_WIDTH - 1;

    return new_plyr;

}
    
