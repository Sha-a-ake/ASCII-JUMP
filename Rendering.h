#ifndef __RENDERING__
#define __RENDERING__

#define WINDOW_X 3
#define WINDOW_Y 3
#define WINDOW_HEIGHT 45
#define WINDOW_WIDTH 65

#include "Platform.h"

void render_all(platform* chunk, player* p);
void render_static();
void clear_screen();
void render_platform(platform p);
void render_player(player p);

#endif
