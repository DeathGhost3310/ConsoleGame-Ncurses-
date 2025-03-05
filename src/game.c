#include "../include/game.h"
#include "../include/component.h"
#include "../include/transformComp.h"
#include "../include/moveComp.h"
#include "../include/unitComp.h"
#include "../include/object.h"
#include "../include/objectMap.h"
#include "../include/playerObj.h"
#include "../include/interface.h"


#include "../include/render.h"
#include "../include/headers.h"
#include "../include/input.h"
#include "../include/menu.h"

void init_base(){
   init_render();
}

void init_game(){
   Object *player = init_player(init_Vector2i(15, 15));
   Object *obb = init_object(1, "wall");
   Object *obb2 = init_object(1, "wall2");
   Transform *transfWall2 = init_transform(init_Vector2i(33, 33), ')');
   Transform *transfWall = init_transform(init_Vector2i(11, 10), '#');
   obb->transf = transfWall;
   obb2->transf = transfWall2;
   addComp_object(obb, (Component *)transfWall);
   addComp_object(obb2, (Component *)transfWall2);
   init_objectMap(1000);
   add_object(player);
   add_object(obb);
   add_object(obb2);

}

void game_loop(){
   Bool gameWork = True;
   char key = GetKey();
   cls();
   border_draw(130, 35, '|');
   update_interface();
   update_objects();
   while(gameWork == True){
      UpdateKey();
      key = GetKey();
      if(key == 'e')
         gameWork = False;

      cls();
      border_draw(130, 35, '|');
      update_interface();
      update_objects();
   }
   destruct_game();
   menu_loop();
}

void destruct_game(){
   destruct_interface();
   destruct_objMap();
}

void destruct_base(){
   destruct_render();
}

