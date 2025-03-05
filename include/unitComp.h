#ifndef UNITCOMP_H
#define UNITCOMP_H

#include <stdlib.h>

#include "component.h"
#include "headers.h"

typedef struct{
   Component base;
   int hp;
   void *object;
}Unit;

Unit* init_unit(int hp, void *obj);

void damage_unit(void *self, int damage);

void update_unit(void *self);

void destruct_unit(void *self);

#endif
