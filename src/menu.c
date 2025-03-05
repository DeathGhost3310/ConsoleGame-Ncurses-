#include "../include/game.h"
#include "../include/headers.h"
#include "../include/input.h"

#include "../include/render.h"
#include <ncurses.h>

static char game_prev[1000] = " ccccccc    cccccc    ccc        cc\ncccccccc    cccccc    cccc       cc\ncc        cc      cc  cc cc      cc\ncc        cc      cc  cc  cc     cc\ncc        cc      cc  cc   cc    cc\ncc        cc      cc  cc    cc   cc\ncc        cc      cc  cc     cc  cc\ncc        cc      cc  cc      cc cc\ncc        cc      cc  cc       cccc\ncccccccc    cccccc    cc        ccc\n ccccccc    cccccc    cc         cc";

static short selector = 0;
static char key = '0';
static char menu_cursor = '>';

static char startButton[10] = "START";
static char exitButton[10] = "EXIT";

static Vector2i pos;

void menu_render(){
   Vector2i time_pos = pos;
   printw("%s", game_prev);
   if(selector == 0){
      mvprintw(time_pos.y, time_pos.x, "%c%s", menu_cursor, startButton);
      time_pos.y++;
      mvprintw(time_pos.y, time_pos.x, "%s", exitButton);
   }
   else if(selector == 1){
      mvprintw(time_pos.y, time_pos.x, "%s", startButton);
      time_pos.y++;
      mvprintw(time_pos.y, time_pos.x, "%c%s", menu_cursor, exitButton);
   }
}

void update_selector(){
   if(key == 'w' && selector > 0)
      selector--;
   else if(key == 's' && selector < 1)
      selector++;
}

void menu_loop(){
   Bool menuWork = True;
   
   pos = init_Vector2i(75, 15);

   while(menuWork == True){
      cls();
      menu_render();
      UpdateKey();
      key = GetKey();
      update_selector();
      if(key == 'd'){
         if(selector == 0){
            init_game();
            game_loop();
         }
         else if(selector == 1){
            menuWork = False;
            break;
         }
      }
   }

   destruct_base();
}
