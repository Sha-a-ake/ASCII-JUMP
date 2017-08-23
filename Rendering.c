#include <stdio.h>
#include <curses.h>

#include "Rendering.h"
#include "Generating.h"
#include "Platform.h"
#include "Player.h"
#include "Game.h"


void render_all(platform* all_platforms, player* p, int height)
{
    int ch;
    int camera_h = height;

    clear_screen();
    render_static();

    for (int i = 0; i < PLATFORM_COUNT; ++i)
        render_platform(all_platforms[i], camera_h, height);


    render_player(*p, camera_h);

    attron(A_STANDOUT);
    move(0, WINDOW_X);
    printw("height: %d\n", height);
    move(0, 0);
    attroff(A_STANDOUT);
}

void render_static()
{
    attron(A_DIM);

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

    attroff(A_DIM);
}

void clear_screen()
{
    clear();
}

void render_platform(platform p, int camera_h, int height)
{
    attron(A_BOLD);

    move(plnkh(p) + WINDOW_Y + camera_h, plnkls(p) + WINDOW_X);

    if (plnkh(p) + camera_h < WINDOW_HEIGHT)
    {
        addch('<');

        for (int i = 0; i < PLATFORM_WIDTH - 2; i++)
            addch('=');

        addch('>');
    }

    attroff(A_BOLD);
}

void render_player(player p, int camera_h)
{
    move(plyrth(p) + WINDOW_Y + camera_h, plyrls(p) + WINDOW_X);
    printw(PLAYER1);
    move(plyrth(p) + 1 + WINDOW_Y + camera_h, plyrls(p) + WINDOW_X);
    printw(PLAYER2);
    move(plyrth(p) + 2 + WINDOW_Y + camera_h, plyrls(p) + WINDOW_X);
    printw(PLAYER3);
    move(plyrth(p) + 3 + WINDOW_Y + camera_h, plyrls(p) + WINDOW_X);
    printw(PLAYER4);
}