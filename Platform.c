#include "Platform.h"
#include "Player.h"
#include "stdbool.h"

bool player_collision(platform plat, player play)
{
    if ((plat.y == play.y) && (play.x >= plat.x) && (play.x <= plat.x + PLATFORM_WIDTH))
        return true;
    else
        return false;
}

