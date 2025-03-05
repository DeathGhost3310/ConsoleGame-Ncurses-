#include "../include/input.h"

static char key = '0';

char GetKey(){
   return key;
}

void UpdateKey(){
   key = getch();
}

void Setkey(char k){
   key = k;
}
