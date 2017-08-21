#include <stdlib.h>
#include <time.h>
#include <curses.h>

#include "Generating.h"
#include "Platform.h"
#include "Rendering.h"

int random_int(const int min, const int max)
{
    srand(time(NULL));
    int r = rand() % max + min;
    return r;

}

void gen_chunk(platform* chunk)
{

    for (int i = 0; i < 3; ++i)
    {
        chunk[i] = new_platform(random_int(1, WINDOW_WIDTH), random_int(1, WINDOW_HEIGHT));
    }

}