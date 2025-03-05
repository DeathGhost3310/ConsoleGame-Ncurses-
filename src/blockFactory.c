#include "../include/blockFactory.h"


void create_unbreakableBlock(Vector2i pos, char symbol){
   Object *obj = init_object(1, "UnbreakableBlock");
   Transform *transf = init_transform(pos, symbol);
   addComp_object(obj, (Component *)transf);
   obj->transf = transf;
   add_object(obj);
}

void create_block(Vector2i pos, char symbol, int hp){
   Object *obj = init_object(2, "Block");
   Transform *transf = init_transform(pos, symbol);
   Unit *unitC = init_unit(hp, obj);
   obj->transf = transf;
   addComp_object(obj, (Component *)unitC);
   addComp_object(obj, (Component *)transf);

   add_object(obj);
}

