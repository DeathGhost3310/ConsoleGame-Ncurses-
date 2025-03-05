#ifndef COMPONENT_H
#define COMPONENT_H

#include "headers.h"

typedef enum {
   comp, 
   transform
}CompType;

typedef struct{
   void (*Update)(void *);
   void (*Destruct)(void *);
   Bool Active;
}Component;



#endif
