#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "component.h"
#include "headers.h"

#include <ncurses.h>
#include <stdlib.h>

typedef struct{
   Component base;
   Vector2i pos;
   char symbol;
}Transform;

Transform* init_transform(Vector2i pos, char sym);

void update_transform(void *self);

void destruct_transform(void *self);




#endif
