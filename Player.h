#ifndef __PLAYER__
#define __PLAYER__

#define PLAYER_HEIGHT 4
#define PLAYER_WIDTH 3

typedef struct p
{
    int   x;
    float x_real;
    int   y;
    float y_real;
} player;

// Create new player
player new_player(int x, int y);

// Player left side
int plyrls(player plyr);
// Player right side
int plyrrs(player plyr);
// Player top height
int plyrth(player plyr);
// Player bottom height
int plyrbh(player plyr);

#endif
