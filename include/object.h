#ifndef OBJECT_H
#define OBJECT_H

#include "component.h"
#include "transformComp.h"
#include "moveComp.h"
#include "unitComp.h"
#include "headers.h"

typedef struct{
   Component **components;
   Transform *transf;
   Bool Active;
   char *name;
   unsigned short size;
   unsigned short count;
}Object;

Object* init_object(unsigned short size, char name[]);

void addComp_object(void *self, Component *comp);

void update_object(void *self);

Transform* get_transform(void *self);

void destruct_object(void *self);

#endif
