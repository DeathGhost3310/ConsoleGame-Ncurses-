#ifndef INTERFACE_H
#define INTERFACE_H

#include "headers.h"
#include "component.h"
#include "unitComp.h"
#include "moveComp.h"
#include "transformComp.h"
#include "object.h"
#include "objectMap.h"


typedef struct{
   Object *obj;
   Vector2i pos;
   Unit *unit;
   Transform *transf;
}Interface;

void init_interface(Object *obj, Unit *unitC, Vector2i pos);

void update_interface();

void destruct_interface();


#endif
