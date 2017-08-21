#ifndef __PLAYER__
#define __PLAYER__

#define PLAYER_HEIGHT 3
#define PLAYER_WIDTH 3

// Chainging height may require editing player rendering function
#define PLAYER1  " o "
#define PLAYER2  "/O\\"
#define PLAYER3  "_|_"


typedef struct p
{
    int   x;
    float x_real;
    int   y;
    float y_real;

    float Vy;

} player;

// Create new player
player new_player(float x, float y);

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

#endif
