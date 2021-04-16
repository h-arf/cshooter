#include "bar.h"
#define B_SIZE 11
char*b_item="|-|-|-|-|-";
int b_n;
char**b_disp(){
    char*barl=malloc(sizeof(char)*(b_n*B_SIZE));
    char**ret=malloc(sizeof(char*)*2);
    ret[1]=NULL;
    for (int n=0;n<b_n;n++){
        strcat(barl,b_item);
    }
    ret[0]=barl;
    return ret;
}
void b_xylh(int*tf);//tf must be 4*sizeof(int)
void b_setup();
void b_cleanup();