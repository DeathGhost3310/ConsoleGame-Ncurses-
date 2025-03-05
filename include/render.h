#ifndef RENDER_H
#define RENDER_H

#include <ncurses.h>

#include "headers.h"

void init_render();

void draw(Vector2i pos, char sym);

void print_text(char* text, Vector2i pos);

void border_draw(int x, int y, char sym);

void cls();

void destruct_render();


#endif
