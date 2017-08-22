#include <stdio.h>
#include <curses.h>

#include "Rendering.h"
#include "Generating.h"
#include "Platform.h"
#include "Player.h"


void render_all(platform* current_chunk, platform* top_chunk, player* p, int height)
{
    int ch;
    int camera_h = height;

    clear_screen();
    render_static();

    // if (camera_h == WINDOW_HEIGHT)
    // {
    //     current_chunk = top_chunk;
    //     gen_chunk(top_chunk, -WINDOW_HEIGHT);
    // }

    for (int i = 0; i < 5; ++i)
    {
        render_platform(current_chunk[i], camera_h);
        render_platform(top_chunk[i], camera_h);
    }

    render_player(*p);

    move(0, WINDOW_X);
    printw("height: %d\n", height);
    move(0, 0);
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

void clear_screen()
{
    for (int i = 1; i <= WINDOW_HEIGHT - 1; i++)
    {
        move(WINDOW_Y + i, WINDOW_X + 1);
        for (int j = 0; j <= WINDOW_WIDTH - 3; j++)
	addch(' ');
    }
}

void render_platform(platform p, int camera_h)
{
    move(plnkh(p) + WINDOW_Y + camera_h, plnkls(p) + WINDOW_X);

    if (plnkh(p) + camera_h < WINDOW_HEIGHT)
    {
        addch('<');

        for (int i = 0; i < PLATFORM_WIDTH - 2; i++)
        {
            // addch('=');
            printw("%d", p.y);
            break;
        }

        addch('>');
    }
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

