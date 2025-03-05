#ifndef OBJECTMAP_H
#define OBJECTMAP_H

#include "object.h"
#include "headers.h"


typedef enum{
   Menu,
   Game
}GameState;


void init_objectMap(unsigned int max_size);

Object* get_TransformObject(Vector2i pos);

Bool check_pos(Vector2i pos);

void set_ObjectsState();

void update_objects();

Object* get_objectbyName(char *name);

void add_object(Object *obj);

void delete_obj(Object *obj);

void destruct_objMap();

#endif
