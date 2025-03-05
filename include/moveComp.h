#ifndef MOVECOMP_H
#define MOVECOMP_H

#include "component.h"
#include "transformComp.h"
#include "input.h"

typedef struct{
   Component base;
   Transform *transf;
}MoveComp;

MoveComp* init_move(Transform *transf);

void update_move(void *self);

void destruct_move(void *self);

#endif
