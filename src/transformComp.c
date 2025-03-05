#include "../include/transformComp.h"

#include "../include/render.h"

Transform* init_transform(Vector2i pos, char sym){
   Transform *transf = malloc(sizeof(Transform));
   
   transf->base.Update = update_transform;
   transf->base.Destruct = destruct_transform;
   transf->pos = pos;
   transf->symbol = sym;
   transf->base.Active = True;

   return transf;
}


void update_transform(void *self){
   Transform *transf = (Transform *)self;
   if(transf->base.Active == False)
      return;

   draw(transf->pos, transf->symbol);
}


void destruct_transform(void *self){
   Transform *transf = (Transform *)self;

   free(transf);
}
