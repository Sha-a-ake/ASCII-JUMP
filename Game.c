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
#include "Game.h"

int game_cycle()
{
    int ch;
    bool game_on = true;
    int i = 0, y = 0;

    int height = 0; // very importaint var

    platform all_platforms[PLATFORM_COUNT];
    gen_platform_init(all_platforms);

    player my_plyr = new_player(7, 7, 1);

    render_static();

    ch = getch();
    move(0, 0);
    putchar(ch);

    while (game_on)
    {

        //
        for (int i = 0; i < PLATFORM_COUNT; ++i) // function prototype, i also added "dead" bool to struct a
        {
            if (plnkh(all_platforms[i]) + height >= WINDOW_HEIGHT)
            {
                gen_platform(&all_platforms[i], height);
            }
        }
        //

        render_all(all_platforms, &my_plyr, height);

        for (int i = 0; i < PLATFORM_COUNT; ++i) 
            if (plnkcln(all_platforms[i], my_plyr))
                my_plyr = plyrjmp(my_plyr);

        ch = getch();

        if (ch != ERR)
        {
            if (ch == 27)
                break;
            else if (ch == KEY_RIGHT)
                my_plyr = plyrmv(my_plyr, 1, 0);
            else if (ch == KEY_LEFT)
                my_plyr = plyrmv(my_plyr, -1, 0);
            // for debug
            else if (ch == 'w')
                height += 1;
            else if (ch == 's')
                height -= 1;
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
    set_escdelay(0);

    game_cycle();

    endwin();

    return 0;
}
