#include "../include/game.h"
#include "../include/component.h"
#include "../include/transformComp.h"
#include "../include/unitComp.h"
#include "../include/object.h"
#include "../include/objectMap.h"
#include "../include/playerObj.h"
#include "../include/blockFactory.h"
#include "../include/interface.h"


#include "../include/render.h"
#include "../include/headers.h"
#include "../include/input.h"

void init_base(){
   init_render();
}

void init_game(){
   Object *player = init_player(init_Vector2i(15, 15));
   Object *obb = init_object(1, "wall");
   Object *obb2 = init_object(1, "wall2");
   Transform *transfWall2 = init_transform(init_Vector2i(33, 33), ')');
   Transform *transfWall = init_transform(init_Vector2i(11, 10), '#');
   addComp_object(obb, (Component *)transfWall);
   addComp_object(obb2, (Component *)transfWall2);
   init_objectMap(1000);
   add_object(player);
   add_object(obb);
   add_object(obb2);
   for(int i = 0;i < 10;i++)
      create_block(init_Vector2i(51 + i, 22), '%', 100);
   for(int i = 0;i < 10;i++)
      create_unbreakableBlock(init_Vector2i(51 + i, 20), 'u');

}

void game_loop(){
   Bool gameWork = True;
   char key = GetKey();
   cls();
   border_draw(130, 35, '|');
   update_interface();
   update_objects();
   Object *obj = get_objectbyName("player");
   Unit *unit = (Unit *)get_compByType(obj, unitComp);
   while(gameWork == True){
      UpdateKey();
      key = GetKey();
      if(key == 'e')
         gameWork = False;
      else if(key == 'y')
         delete_obj(obj);
      else if(key == 'g')
         damage_unit(unit, 25);
      cls();
      border_draw(130, 35, '|');
      update_interface();
      update_objects();
   }
   destruct_game();
}

void destruct_game(){
   destruct_interface();
   destruct_objMap();
}

void destruct_base(){
   destruct_render();
}

