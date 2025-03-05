//#include "../include/objectList.h"
//
//
//ObjectList* init_objList(){
//   ObjectList *objList = malloc(sizeof(ObjectList));
//   objList->objCell = malloc(sizeof(Objcell));
//   objList->count = 0;
//   objList->add = add_obj;
//   objList->pop = pop;
//   objList->next = next;
//   objList->deleteObj = delete_obj;
//   
//   return objList;
//}
//
//void add_obj(void *self, Object *obj){
//   ObjectList *objList = (ObjectList *)self;
//   if(objList->count == 0)
//      objList->objCell->front = obj;
//   
//
//   objList->count++;
//}
//
//void next(void *self){}
//
//void pop(void *self){}
//
//void delete_obj(void *self, Object *obj){}
//
//void destruct_objectList(ObjectList *objList){}
