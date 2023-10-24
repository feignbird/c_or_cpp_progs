#include<stdio.h>
int main(int argc, char *argv[]){
    int x=1, z[2] = {10, 11};
    int *p = NULL;
    p = &x;
    *p = 10;
    p = &z[1];
    printf("x: %d -- p: %x -- &z[0]: %x -- (&z[0]+1): %x  --- *(&z[0]+1): %d", x, p, &z[0], (&z[0]+1), *(&z[0]+1));
    return 0;
}