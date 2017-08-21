#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>

#include "Rendering.h"
#include "Generating.h"
#include "Platform.h"

int game_cycle()
{
    int ch;
    bool game_on = true;
    int i = 0, y = 0;

    platform my_chunk[3];
    gen_chunk(my_chunk);

    while (game_on)
    {
        game_on = render_all(my_chunk);
    }

    return 0;
}

int main()
{
    printf("Hello world!\n");

	srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    game_cycle();

    endwin();

    return 0;
}
