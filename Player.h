#ifndef __PLAYER__
#define __PLAYER__

#define PLAYER_HEIGHT 3
#define PLAYER_WIDTH 5

// Chainging height may require editing player rendering function
#define PLAYER1  " _!_ "
#define PLAYER2  "(0_0)"
#define PLAYER3  " ||| "

#define GRAVITATION 0.1

typedef struct p
{
    int   x;
    float x_real;
    int   y;
    float y_real;

    float Vy;

} player;

// Create new player
player new_player(float x, float y, float Vy);

// Player left side
int plyrls(player plyr);
// Player right side
int plyrrs(player plyr);
// Player top height
int plyrth(player plyr);
// Player bottom height
int plyrbh(player plyr);
// Player y speed
int plyrvy(player plyr);

player plyrmv(player p, float dx, float dy);
player plyrfall(player p);

#endif
