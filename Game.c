/*
A simple doodle-jump like terminal game
Copyright © 2017 Anton Makhtinger, Evgeniy Mazayshvilly

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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
        if (ch == 27) //ESC
            return 0;
        else if (ch == KEY_RIGHT) // ->
            player_mv(p, 2, 0);
        else if (ch == KEY_LEFT) // <-
            player_mv(p, -2, 0);
        else if (ch == 265) // F1
            read_help();
        else if (ch == 266) // F2
            read_license();
        // for debug
        else if (ch == 'w')
            *height += 1;
        else if (ch == 's')
            *height -= 1;
    }

    player_fall(p);

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


    // Here be loop
    while (get_action(&my_plyr, &height))
    {
        // Controls alalysis

        // if screen needed to move up
        if (plyrbh(my_plyr) + height < WINDOW_HEIGHT/2)
            height += 1;

        // Checking gameover
        if (gameover(my_plyr, height, all_platforms))
            break;

        // Platform generation
        for (int i = 0; i < PLATFORM_COUNT; ++i)
            if (plnkh(all_platforms[i]) + height >= WINDOW_HEIGHT)
                gen_platform(&all_platforms[i], height);

        // Screen rendering
        render_all(all_platforms, &my_plyr, height);


        // Collision checking
        for (int i = 0; i < PLATFORM_COUNT; ++i) 
            if (plnkcln(all_platforms[i], my_plyr))
                player_jmp(&my_plyr);

        // Clearing the input buffer and falling to sleep
        tcflush(0, TCIFLUSH);
        usleep(50000);

    }

    return 0;
}

bool gameover(player p, int height, platform* all_platforms)
{
    if (plyrbh(p) + height - plyrvy(p) > WINDOW_HEIGHT)
    {
        int ch = ERR;
        flash();
        clear();

        render_all(all_platforms, &p, height);
        attron(A_STANDOUT);
        render_player(p, height, WINDOW_X, WINDOW_Y);
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

void read_license()
{
    int ch = ERR;
    int pos_y =  WINDOW_Y + 5;
    int pos_x =  WINDOW_X + 5;

    clear();

    move(WINDOW_Y, WINDOW_X);
    hline('#', 85);
    vline('#', 35);
    move(WINDOW_Y + 35, WINDOW_X);
    hline('#', 85);
    move(WINDOW_Y, WINDOW_X + 85 -1);
    vline('#', 35);
    move(pos_y , pos_x);

    attron(A_BOLD);
    mvaddstr(++pos_y, pos_x, "                   ____ ____ ____ _ _     _ _  _ _  _ ___  ");
    mvaddstr(++pos_y, pos_x, "                   |__| [__  |    | |     | |  | |\\/| |__] ");
    mvaddstr(++pos_y, pos_x, "                   |  | ___] |___ | |    _| |__| |  | |    ");
    mvaddstr(++pos_y, pos_x, "");
    mvaddstr(++pos_y, pos_x, "");
    mvaddstr(++pos_y, pos_x, "Copyright © 2017 Anton Makhtinger, Evgeniy Mazayshvilly");
    mvaddstr(++pos_y, pos_x, "");
    attron(A_STANDOUT); mvaddstr(++pos_y, pos_x, "WARRANTY"); attroff(A_STANDOUT);
    mvaddstr(++pos_y, pos_x, "THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY");
    mvaddstr(++pos_y, pos_x, "APPLICABLE LAW. EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT");
    mvaddstr(++pos_y, pos_x, "HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM 'AS IS' WITHOUT WARRANTY");
    mvaddstr(++pos_y, pos_x, "OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,");
    mvaddstr(++pos_y, pos_x, "THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR");
    mvaddstr(++pos_y, pos_x, "PURPOSE. THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM");
    mvaddstr(++pos_y, pos_x, "IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF");
    mvaddstr(++pos_y, pos_x, "ALL NECESSARY SERVICING, REPAIR OR CORRECTION.");
    mvaddstr(++pos_y, pos_x, "");
    mvaddstr(++pos_y, pos_x, "");
    attron(A_STANDOUT); mvaddstr(++pos_y, pos_x, "CONDITIONS"); attroff(A_STANDOUT);
    mvaddstr(++pos_y, pos_x, "You should have received a copy of the GNU General Public License");
    mvaddstr(++pos_y, pos_x, "along with this program. If not, see");
    mvaddstr(++pos_y, pos_x, "<http://www.gnu.org/licenses/>.");
    mvaddstr(++pos_y, pos_x, "");
    attroff(A_BOLD);

    attron(A_DIM);
    mvaddstr(++pos_y, pos_x, "(press any key to continue playing)");
    attroff(A_DIM);

    while (ch == ERR)
        ch = getch();
}

void read_help()
{
    int ch = ERR;
    int pos_y =  WINDOW_Y + 5;
    int pos_x =  WINDOW_X + 5;

    clear();

    move(WINDOW_Y, WINDOW_X);
    hline('#', 82);
    vline('#', 24);
    move(WINDOW_Y + 24, WINDOW_X);
    hline('#', 82);
    move(WINDOW_Y, WINDOW_X + 82 -1);
    vline('#', 24);
    move(pos_y , pos_x);                                                                                           

    attron(A_BOLD);
    mvaddstr(++pos_y, pos_x, "  _  _ ____ ____    ___ _  _ ____    ____ ____ ____ ____ _ _ _ ____");
    mvaddstr(++pos_y, pos_x, "  |  | [__  |___     |  |__| |___    |__| |__/ |__/ |  | | | | [__ ");
    mvaddstr(++pos_y, pos_x, "  |__| ___] |___     |  |  | |___    |  | |  \\ |  \\ |__| |_|_| ___]");
    mvaddstr(++pos_y, pos_x, "");
    mvaddstr(++pos_y, pos_x, "");
    mvaddstr(++pos_y, pos_x, "");
    mvaddstr(++pos_y, pos_x, "");
    mvaddstr(++pos_y, pos_x, "                  .                               .      ");
    mvaddstr(++pos_y, pos_x, "                .;;.......... ..     .. ..........;;.    ");
    mvaddstr(++pos_y, pos_x, "              .;;;;::::::::::..       ..::::::::::;;;;.  ");
    mvaddstr(++pos_y, pos_x, "               ':;;:::::::::: . .   . . ::::::::::;;:'   ");
    mvaddstr(++pos_y, pos_x, "                 ':                               :'     ");
    mvaddstr(++pos_y, pos_x, "");
    mvaddstr(++pos_y, pos_x, "");
    mvaddstr(++pos_y, pos_x, "");
    attroff(A_BOLD);

    mvaddstr(++pos_y, pos_x, "(press any key to continue playing)");

    while (ch == ERR)
        ch = getch();
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
