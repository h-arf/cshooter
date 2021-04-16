#include "enemy.h"
static const int e_l=9;
static const int e_h=3;
static const int e_y=0;
int e_x=0;
bool e_shot=false;
bool e_dir=true;
int p=-1;
char**e_disp_r,**e_disp_s;
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
    e_disp_r=malloc(4*sizeof(char*));
    e_disp_r[3]=NULL;
    *e_disp_r=  "   <->   ";
    e_disp_r[1]=" <><-><> ";
    e_disp_r[2]="<><>-<><>";
    e_disp_s=malloc(4*sizeof(char*));
    e_disp_s[3]=NULL;
    *e_disp_s=  "   <->   ";
    e_disp_s[1]=" <><-><> ";
    e_disp_s[2]="<><| |><>";
}
char**e_disp(){
    return e_shot?e_disp_s:e_disp_r;
}
void e_cleanup(){
    free(e_disp_r);
    free(e_disp_s);
}
void e_shoot(){
    if ((time(NULL)-p)==0)
        return;
    if (e_shot){
        e_shot=false;
        return;
    }
    if (rand()%5==1)
        e_shot=!e_shot;
    p=time(0);
}
