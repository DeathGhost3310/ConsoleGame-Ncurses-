#ifndef COMPONENT_H
#define COMPONENT_H

#include "headers.h"

typedef enum {
   comp, 
   transformComp,
   moveComp,
   unitComp,
}CompType;

typedef struct{
   void (*Update)(void *);
   void (*Destruct)(void *);
   CompType type;
   Bool Active;
}Component;



#endif
