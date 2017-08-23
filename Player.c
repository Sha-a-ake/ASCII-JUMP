
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

// Moves the player on the given dx and dy
player plyrmv(player p, float dx, float dy)
{
    player new_plyr = new_player(p.x_real + dx, p.y_real + dy, p.Vy);


    return new_plyr;
}

// Makes the player fal. Literally. And updates his situation. Badly needs a rewrite
player plyrfall(player p)
{
    player new_plyr = new_player(p.x_real, p.y_real - p.Vy, p.Vy - GRAVITATION);

    if (p.y >= WINDOW_HEIGHT-PLAYER_HEIGHT-1) 
        new_plyr.Vy = 1.5;

    if (plyrls(p) < 2)
        new_plyr.x_real = 2;

    if (plyrrs(p) > WINDOW_WIDTH - 2)
        new_plyr.x_real = WINDOW_WIDTH - PLAYER_WIDTH - 1;

    return new_plyr;
}

player plyrjmp(player p)
{
    player new_plyr = new_player(p.x_real, p.y_real, 1.5);

    return new_plyr;
} 
