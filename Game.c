#include <stdio.h>
#include <stdbool.h>
#include "Rendering.h"

int game_cycle()
{
    bool game_on = true;

    while (game_on)
    {
        render_all();
        game_on = false;
    }

    return 0;
}

int main()
{
    printf("Hello world!\n");

    game_cycle();

    return 0;
}
