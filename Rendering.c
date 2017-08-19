#include <stdio.h>
#include <curses.h>

bool render_all(int i, int y)
{
    int ch;

    if ((ch = getch()) != ERR)
        return false;
    else
        printw("%d", i);
    move(y, 0);
    return true;
}
