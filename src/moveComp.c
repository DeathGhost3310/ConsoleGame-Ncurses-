#include "../include/moveComp.h"
#include "../include/objectMap.h"
#include "../include/headers.h"

MoveComp* init_move(Transform *transf){
   MoveComp *moveC = malloc(sizeof(MoveComp));
   moveC->transf = transf;
   
   moveC->base.Update = update_move;
   moveC->base.Destruct = destruct_move;
   moveC->base.Active = True;
   moveC->base.type = moveComp;

   return moveC;
}


void update_move(void *self){
   MoveComp *move = (MoveComp *)self;
   Transform *transf = move->transf;
   if(move->base.Active == False || transf->base.Active == False)
      return;
   
   char key = GetKey();
   
   Vector2i checkpos = transf->pos;
   if(key == 'w'){
      checkpos.y -= 1;
      if(check_pos(checkpos) == False && transf->pos.y > 0)
         transf->pos.y--;
   }
   else if(key == 's'){
      checkpos.y += 1;
      if(check_pos(checkpos) == False && transf->pos.y < 34)
         transf->pos.y++;
   }
   if(key == 'd'){
      checkpos.x += 1;
      if(check_pos(checkpos) == False && transf->pos.x < 129)
         transf->pos.x++;
   }
   else if(key == 'a'){
      checkpos.x -= 1;
      if(check_pos(checkpos) == False && transf->pos.x > 0)
         transf->pos.x--;
   }
}

void destruct_move(void *self){
   MoveComp *move = (MoveComp *)self;

   free(move);
}

