#include "../include/interface.h"
#include <stdlib.h>
#include <ncurses.h>


static Interface *interface;

static char *text;

void init_interface(Object *obj, Unit *unitC, Vector2i pos){
   interface = malloc(sizeof(Interface));
   interface->obj = obj;
   interface->pos = pos;
   interface->unit = unitC;
   interface->transf = interface->obj->transf;

   text = malloc(sizeof(char) * 300);
}

void update_interface(){
   mvprintw(interface->pos.y, interface->pos.x, "HP: %d POS: X: %d Y: %d",
   interface->unit->hp, interface->transf->pos.x, interface->transf->pos.y);  
}

void destruct_interface(){
   free(interface);
}




