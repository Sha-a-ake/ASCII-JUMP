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

#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <stdbool.h>

#include "Generating.h"
#include "Platform.h"
#include "Rendering.h"
#include "Game.h"

int random_int(const int min, const int max)
{
    return rand() % (max - min) + min;
}

void gen_platform(platform* plat, int height)
{
    *plat = new_platform(random_int(0, WINDOW_WIDTH - PLATFORM_WIDTH), 0 - height);
}

void gen_platform_init(platform* platforms)
{

    for (int i = 0; i < PLATFORM_COUNT; ++i)
    {
        platforms[i] = new_platform(random_int(0, WINDOW_WIDTH - PLATFORM_WIDTH), random_int(0, 7) + 6*i);
    }

}