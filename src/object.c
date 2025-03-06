#include "../include/object.h"

Object* init_object(unsigned short size, char *name){
   Object *obj = malloc(sizeof(Object));
   Component **components = malloc(sizeof(Component*) * size);
   obj->transf = NULL;

   obj->components = components;
   obj->count = 0;
   obj->size = size;
   obj->name = name;
   obj->Active = True;

   return obj;
}

void addComp_object(void *self, Component *comp){
   Object *obj = (Object *)self;
   if(obj->size <= obj->count)
      return;
   obj->components[obj->count] = comp;
   
   if(comp->type == transformComp)
      obj->transf = (Transform *)comp;

   obj->count++;
}

void update_object(void *self){
   Object *obj = (Object *)self;
   if(obj->Active == False)
      return;

   
   for(int i = 0;i < obj->count;i++)
      obj->components[i]->Update(obj->components[i]);
}

Transform* get_transform(void *self){
   Object* obj = (Object *)self;
   if(obj->transf != NULL){
      return obj->transf;
   }
   return obj->transf;
}

Component* get_compByType(Object *obj, CompType type){
   for(int i = 0;i < obj->count;i++){
      if(obj->components[i]->type == type)
         return obj->components[i];
   }

   return NULL;
}

void destruct_object(void *self){
   Object *obj = (Object *)self;

   for(int i = 0;i < obj->count;i++)
      obj->components[i]->Destruct(obj->components[i]);
   
   free(obj->components);
   free(obj);
   obj = NULL;
}










