#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>

#include "Rendering.h"
#include "Generating.h"
#include "Platform.h"

int game_cycle()
{
    int ch;
    bool game_on = true;
    int i = 0, y = 0;

    platform my_chunk[3];
    player my_plyr = new_player(7, 7);

    gen_chunk(my_chunk);

    render_static();

    while (game_on)
    {
        my_plyr = plyrmv(my_plyr, 1, 0);

        game_on = render_all(my_chunk, &my_plyr);

        sleep(1);
    }

    return 0;
}

int main()
{

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
