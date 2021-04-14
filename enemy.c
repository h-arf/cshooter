#include "enemy.h"
static const int e_l=3;
static const int e_h=2;
static const int e_y=0;
int e_x=0;
bool e_dir=true;
void e_move(){
    if (e_dir)
        e_x++;
    else
        e_x--;
    if ((e_x+e_l)>=COLS||e_x<=0)
        e_dir=!e_dir;
}
void e_xylh(int*tf){//tf must be 4*sizeof(int)
    tf[0]=e_x;
    tf[1]=e_y;
    tf[2]=e_l;
    tf[3]=e_h;
}
void e_setup(){
    e_disp=malloc(3*sizeof(char*));
    e_disp[2]=NULL;
    *e_disp=" ^ ";
    e_disp[1]="<->";
}
void e_cleanup(){
    free(e_disp);
}