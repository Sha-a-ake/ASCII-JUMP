#include <stdio.h>
#include <curses.h>

#include "Rendering.h"
#include "Generating.h"
#include "Platform.h"
#include "Player.h"
#include "Game.h"


void render_all(platform* all_platforms, player* p, int height)
{
    int camera_h = height;

    clear();
    render_window(WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT);
    render_window(80, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT);

    for (int i = 0; i < PLATFORM_COUNT; ++i)
    {
        render_platform(all_platforms[i], camera_h, height, WINDOW_X, WINDOW_Y);
        render_platform(all_platforms[i], camera_h, height, 80, WINDOW_Y);
    }

    render_player(*p, camera_h, WINDOW_X, WINDOW_Y);
    render_player(*p, camera_h, 80, WINDOW_Y);

    // Prints the height debug thingie
    attron(A_STANDOUT);
    move(WINDOW_Y-1, WINDOW_X);
    printw("height: %d\n", height);
    move(0, 0);
    attroff(A_STANDOUT);
}

// Types the window borders
void render_window(int x, int y, int x_len, int y_len)
{
    attron(A_DIM);

    move(y, x);

    for (int i = 0; i < x_len; i++)
        addch('-');

    for (int i = 1; i < y_len; i++)
    {
        move(y + i, x);
        addch('|');

        move(y + i, x + x_len - 1);
        addch('|');
    }

    move(y + y_len, x);

    for (int i = 0; i < x_len; i++)
        addch('-');

    attroff(A_DIM);
}

// Draws one given platform
void render_platform(platform p, int camera_h, int height, int x, int y)
{
    attron(A_BOLD);

    move(plnkh(p) + y + camera_h, plnkls(p) + x);

    if (plnkh(p) + camera_h < WINDOW_HEIGHT)
    {
        addch('<');

        for (int i = 0; i < PLATFORM_WIDTH - 2; i++)
            addch('=');

        addch('>');
    }

    attroff(A_BOLD);
}

// Draws one given player
void render_player(player p, int camera_h, int x, int y)
{
    move(plyrth(p) + y + camera_h, plyrls(p) + x);
    printw(PLAYER1);
    move(plyrth(p) + 1 + y + camera_h, plyrls(p) + x);
    printw(PLAYER2);
    move(plyrth(p) + 2 + y + camera_h, plyrls(p) + x);
    printw(PLAYER3);
    move(plyrth(p) + 3 + y + camera_h, plyrls(p) + x);
    printw(PLAYER4);
}
