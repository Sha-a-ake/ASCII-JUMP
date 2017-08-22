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