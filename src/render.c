#include "../include/render.h"
#include <stdlib.h>

void init_render(){
   initscr();
   cbreak();
   noecho();
   keypad(stdscr, TRUE);
   curs_set(0);
}

void print_text(char* text, Vector2i pos){
   mvprintw(pos.y, pos.x, "%s\n", text);
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
