#include "../include/unitComp.h"



Unit* init_unit(int hp){
   Unit *unit = malloc(sizeof(Unit));
   unit->hp = hp;
   unit->base.Update = update_unit;
   unit->base.Destruct = destruct_unit;
   unit->base.Active = True;

   return unit;
}

void damage_unit(void *self, int damage){
   Unit *unit = (Unit *)self;
   if(unit->base.Active == False)
      return;
   unit->hp -= damage;
}

void update_unit(void *self){
   Unit *unit = (Unit *)self;
   if(unit->base.Active == False)
      return;

   if(unit->hp <= 0)
      unit->base.Destruct(unit);
}

void destruct_unit(void *self){
   Unit *unit = (Unit *)self;

   free(unit);
}
