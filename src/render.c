#include "../include/render.h"

void init_render(){
   initscr();
   cbreak();
   noecho();
   keypad(stdscr, TRUE);
   curs_set(0);
}

void draw(Vector2i pos, char sym){
   mvprintw(pos.y, pos.x, "%c", sym);
}

void border_draw(int x, int y, char sym){
   for(int i = 0;i < y;i++){
      draw(init_Vector2i(x, i), sym);
   }
}

void cls(){
   clear();
}

void destruct_render(){
   endwin();
}
