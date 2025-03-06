#include "../include/unitComp.h"
#include "../include/objectMap.h"

Unit* init_unit(int hp, void *obj){
   Unit *unit = malloc(sizeof(Unit));
   unit->hp = hp;
   unit->base.Update = update_unit;
   unit->base.Destruct = destruct_unit;
   unit->base.Active = True;
   unit->object = obj;
   unit->base.type = unitComp;

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
      delete_obj(unit->object);
}

void destruct_unit(void *self){
   Unit *unit = (Unit *)self;
   
   free(unit);
}
