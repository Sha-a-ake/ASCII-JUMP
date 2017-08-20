#include <stdio.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>

#include "Rendering.h"
#include "Platform.h"

int game_cycle()
{
    int ch;
    bool game_on = true;
    int i = 0, y = 0;

    while (game_on)
    {
        game_on = render_all(i++, y++);

        if (y == 39)
            y = 0;
        time(0);
    }

    return 0;
}

int main()
{
    printf("Hello world!\n");

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    game_cycle();

    endwin();

    return 0;
}
