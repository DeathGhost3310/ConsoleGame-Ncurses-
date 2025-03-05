#include "../include/playerObj.h"


Object* init_player(Vector2i pos){
   Object *obj = init_object(5, "player");

   Transform *transf = init_transform(pos, '&');
   MoveComp *move = init_move(transf);
   Unit *unitC = init_unit(100);
   obj->transf = transf;

   addComp_object(obj, (Component *)move);
   addComp_object(obj, (Component *)transf);
   addComp_object(obj, (Component *)unitC);

   return obj;
}
