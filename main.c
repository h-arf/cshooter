#include "enemy.h"
#include "bar.h"
#include "ncurses.h"
#include "unistd.h"
#include "includes.h"
void render(char**c,WINDOW*w,int sx,int sy){
    while(*c){
        mvwprintw(w,sy,sx,*c);
        sy++;
        c++;
    }
    wrefresh(w);
}
int main(){
    struct timespec t1,t2;
    t1.tv_nsec=10*10;
    t1.tv_sec=0;
    initscr();
    noecho();
    cbreak();
    start_color();
    e_setup();
    int e_vars[4];
    e_xylh(e_vars);
    WINDOW*enemy_window=stdscr;//newwin(e_vars[3],e_vars[2],e_vars[1]+1,COLS);
    wattron(enemy_window, COLOR_PAIR(1));
    //mvprintw(1,1,"Hello peoples");
    refresh();
    for(;;){
        e_xylh(e_vars);
        render(e_disp,enemy_window,*e_vars,e_vars[1]);
        refresh();
        nanosleep(&t1,&t2);
        e_move();
        break;
    }
    pause();
    endwin();
    e_cleanup();
}
