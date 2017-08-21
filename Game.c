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

        render_all(my_chunk, &my_plyr);

    if ((ch = getch()) != ERR)
    {
        if (ch == KEY_BREAK)
            break;
        else if (ch == KEY_RIGHT)
            my_plyr = plyrmv(my_plyr, 1, 0);
        else if (ch == KEY_LEFT)
            my_plyr = plyrmv(my_plyr, -1, 0);
    }


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
