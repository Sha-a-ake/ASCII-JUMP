#ifndef __RENDERING__
#define __RENDERING__

#define WINDOW_X 3
#define WINDOW_Y 3
#define WINDOW_HEIGHT 20
#define WINDOW_WIDTH 30

#include "Platform.h"

bool render_all(int i, int y);
void render_static();
void render_platform(platform p);
void render_player(player p);

#endif
