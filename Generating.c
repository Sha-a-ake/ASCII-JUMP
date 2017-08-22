#include <stdlib.h>
#include <time.h>
#include <curses.h>

#include "Generating.h"
#include "Platform.h"
#include "Rendering.h"

int random_int(const int min, const int max)
{
    return rand() % (max - min) + min;
}

void gen_chunk(platform* chunk, int height)
{

    for (int i = 0; i < 5; ++i)
    {
        chunk[i] = new_platform(random_int(0, WINDOW_WIDTH - PLATFORM_WIDTH), random_int(0, WINDOW_HEIGHT) - height);
    }

}