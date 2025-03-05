#include "../include/objectMap.h"

static Object **objMap;

static unsigned int count = 0;

static unsigned int *deleteObjsKeys;
static unsigned int delCount = 0;


void init_objectMap(unsigned int max_size){
   objMap = malloc(sizeof(Object*) * max_size);
   deleteObjsKeys = calloc(500 , sizeof(unsigned int));
}

Object* get_TransformObject(Vector2i pos){
   for(unsigned int i = 0;i < count;i++){
      Transform transf = *objMap[i]->transf;
      if(pos.x == transf.pos.x && pos.y == transf.pos.y)
         return objMap[i];
   }

   return NULL;
}

Bool check_pos(Vector2i pos){
   for(unsigned int i = 0;i < count;i++){
      if(objMap[i] == NULL)
         continue;
      Transform *transf = objMap[i]->transf;
      if(transf == NULL)
         continue;
      else if(pos.x == transf->pos.x && pos.y == transf->pos.y)
         return True;
   }

   return False;
}


void set_ObjectsState(){}

void update_objects(){
   for(unsigned int i = 0;i < count;i++){
      if(objMap[i] != NULL)
         update_object(objMap[i]);  
   }
}

void add_object(Object *obj){
   if(delCount > 0){
      unsigned int delKey = deleteObjsKeys[delCount - 1];
      objMap[delKey] = obj;
      deleteObjsKeys[delCount - 1] = 0;
      delCount--;
   }else if(delCount <= 0){
      objMap[count] = obj;
      count++;
   }
}

void delete_obj(Object *obj){
   for(unsigned int i = 0;i < count;i++){
      if(objMap[i] == obj){
         destruct_object(obj);
         objMap[i] = NULL;
         deleteObjsKeys[delCount] = i;
         delCount++;
         return;
      }
   }
}

void destruct_objMap(){
   free(objMap);
}






