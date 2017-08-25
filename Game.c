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

int get_action(player* p, int *height)
{
    int ch = getch();
    if (ch != ERR)
    {
        if (ch == 27)
            return 0;
        else if (ch == KEY_RIGHT)
            *p = plyrmv(*p, 2, 0);
        else if (ch == KEY_LEFT)
            *p = plyrmv(*p, -2, 0);
        // for debug
        else if (ch == 'w')
            *height += 1;
        else if (ch == 's')
            *height -= 1;
    }
    
    return 1;
}


int game_cycle()
{
    int action; // Pressed key
    bool game_on = true; // Checks if the game is still going

    int height = 0;

    platform all_platforms[PLATFORM_COUNT];
    gen_platform_init(all_platforms);

    player my_plyr = new_player(WINDOW_WIDTH/2, WINDOW_HEIGHT - PLAYER_HEIGHT, 1);

    render_static();

    // Here be loop
    while (get_action(&my_plyr, &height))
    {
        // Controls alalysis

        // if screen needed to move up
        if (plyrbh(my_plyr) + height < WINDOW_HEIGHT/2)
            height += 1;

        // Checking gameover
        if (gameover(my_plyr, height))
            break;

        // Making player fall. Literally
        my_plyr = plyrfall(my_plyr);

        // Platform generation
        for (int i = 0; i < PLATFORM_COUNT; ++i)
            if (plnkh(all_platforms[i]) + height >= WINDOW_HEIGHT)
                gen_platform(&all_platforms[i], height);

        // Screen rendering
        render_all(all_platforms, &my_plyr, height);


        // Collision checking
        for (int i = 0; i < PLATFORM_COUNT; ++i) 
            if (plnkcln(all_platforms[i], my_plyr))
                my_plyr = plyrjmp(my_plyr);

        // Clearing the input buffer and falling to sleep
        tcflush(0, TCIFLUSH);
        usleep(50000);

    }

    return 0;
}

bool gameover(player p, int height)
{
    if (plyrbh(p) + height - plyrvy(p) > WINDOW_HEIGHT)
    {
        int ch = ERR;
        flash();
        attron(A_STANDOUT);
        render_player(p, height);
        attroff(A_STANDOUT);

        printw("YOU SUCK! (press any key to exit)");
        refresh();
        sleep(1);
        while (ch == ERR)
        {
            tcflush(0, TCIFLUSH);
            usleep(50000);
            ch = getch();
        }
        return true;
    }
    else
    {
        return false;
    }
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
