/*
A simple doodle-jump like terminal game
Copyright © 2017 Anton Makhtinger, Evgeniy Mazayshvilly

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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
void player_mv(player* p, float dx, float dy)
{
    (*p).x_real += dx;
    (*p).y_real += dy;

    player_upd(p);
}

// Makes the player jump
void player_jmp(player* p)
{
    (*p).Vy = JUMP_HEIGHT;
}

// Makes the player fall
void player_fall(player* p)
{
    (*p).Vy -= GRAVITATION;
    (*p).y_real -= (*p).Vy;

    player_upd(p);
}

// Updates the player position
void player_upd(player* p)
{
    (*p).x = floor((*p).x_real);
    (*p).y = floor((*p).y_real);

    if ((*p).y >= WINDOW_HEIGHT-PLAYER_HEIGHT-1) 
        player_jmp(p);

    if (plyrls(*p) < 2)
        (*p).x_real = WINDOW_WIDTH - PLAYER_WIDTH - 1;

    if (plyrrs(*p) > WINDOW_WIDTH - 2)
        (*p).x_real = 2;

}
