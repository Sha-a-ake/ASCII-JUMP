#include <stdio.h>
#include <curses.h>

#include "Rendering.h"
#include "Generating.h"
#include "Platform.h"
#include "Player.h"


bool render_all(platform* chunk)
{
    int ch;

    player my_plyr = new_player(7, 7);

    render_static();

    for (int i = 0; i < 3; ++i)
    {
        render_platform(chunk[i]);
    }

    move(0, 0);

    if ((ch = getch()) != ERR)
        return false;
    else
        render_player(my_plyr);
    return true;
}

void render_static()
{
    move(WINDOW_Y, WINDOW_X);

    for (int i = 0; i < WINDOW_WIDTH; i++)
        addch('-');

    for (int i = 1; i < WINDOW_HEIGHT; i++)
    {
        move(WINDOW_Y + i, WINDOW_X);
        addch('|');

        move(WINDOW_Y + i, WINDOW_X + WINDOW_WIDTH - 1);
        addch('|');
    }

    move(WINDOW_Y + WINDOW_HEIGHT, WINDOW_X);

    for (int i = 0; i < WINDOW_WIDTH; i++)
        addch('-');

}

void render_platform(platform p)
{
    move(plnkh(p) + WINDOW_Y, plnkls(p) + WINDOW_X);

    for (int i = 0; i < PLATFORM_WIDTH; i++)
        addch('-');
}

void render_player(player p)
{
   move(plyrth(p) + WINDOW_Y, plyrls(p) + WINDOW_X);
   printw(PLAYER1);
   move(plyrth(p) + 1 + WINDOW_Y, plyrls(p) + WINDOW_X);
   printw(PLAYER2);
   move(plyrth(p) + 2 + WINDOW_Y, plyrls(p) + WINDOW_X);
   printw(PLAYER3);

}

