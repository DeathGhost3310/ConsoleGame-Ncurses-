#include <ncurses.h>

#include "../include/game.h"
#include "../include/menu.h"


int main(){
   init_base();
   
   menu_loop();

   return 0;
}
