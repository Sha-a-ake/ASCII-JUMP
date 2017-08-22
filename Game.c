#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#include "Rendering.h"
#include "Generating.h"
#include "Platform.h"
#include "Player.h"

int game_cycle()
{
    int ch;
    bool game_on = true;
    int i = 0, y = 0;

    int height = 0;

    platform current_chunk[5];
    platform top_chunk[5];
    gen_chunk(current_chunk, 0);
    gen_chunk(top_chunk, WINDOW_HEIGHT);

    player my_plyr = new_player(7, 7, 1);

    render_static();

    ch = getch();
    move(0, 0);
    putchar(ch);

    while (game_on)
    {
        // height += 1;

        render_all(current_chunk, top_chunk, &my_plyr, height);

        ch = getch();

        if (ch != ERR)
        {
            if (ch == KEY_BREAK)
                break;
            else if (ch == KEY_RIGHT)
            {
                my_plyr = plyrmv(my_plyr, 1, 0);
                height += 1;
            }
            else if (ch == KEY_LEFT)
            {
                my_plyr = plyrmv(my_plyr, -1, 0);
                height -= 1;
            }
        }

        my_plyr = plyrfall(my_plyr);
        tcflush(0, TCIFLUSH);
        usleep(50000);

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
