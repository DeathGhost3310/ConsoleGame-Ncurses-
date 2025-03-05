#include <ncurses.h>


#include "../include/headers.h"
#include "../include/render.h"
#include "../include/transformComp.h"
#include "../include/moveComp.h"
#include "../include/unitComp.h"
#include "../include/input.h"
#include "../include/object.h"
#include "../include/playerObj.h"
#include "../include/objectMap.h"
#include "../include/interface.h"


int main(){
   init_render();
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

   short gameWork = 1;
   char key = GetKey();
   while(gameWork == 1){
      UpdateKey();
      key = GetKey();
      if(key == 'e')
         gameWork = 0;
          
      cls();
      border_draw(130, 35, '|');
      update_interface();
      update_objects();
   }

   destruct_interface();
   destruct_objMap();  
   destruct_render();
   return 0;
}
