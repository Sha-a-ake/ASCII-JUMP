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

#include "Platform.h"
#include "Player.h"
#include "stdbool.h"

platform new_platform(int x, int y)
{
    platform plnk;
    
    plnk.x = x;
    plnk.y = y;

    return plnk;
}

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


// Checks if the given player and platform are colliding
bool plnkcln(platform plnk, player plyr)
{
    if (((plyrbh(plyr) <= plnkh(plnk)) && (plyrbh(plyr) - plyr.Vy >= plnkh(plnk))) && (plnkls(plnk) <= plyrrs(plyr)) && (plnkrs(plnk) >= plyrls(plyr)))
        return true;
    else
        return false;
}

