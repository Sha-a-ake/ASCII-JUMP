#include <stdio.h>
#include <curses.h>

#include "Rendering.h"
#include "Platform.h"
#include "Player.h"


bool render_all(int i, int y)
{
    int ch;
    platform my_plat = new_platform(3, 4);

    render_static();

    move(0, 0);

    if ((ch = getch()) != ERR)
        return false;
    else
        render_platform(my_plat);
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
