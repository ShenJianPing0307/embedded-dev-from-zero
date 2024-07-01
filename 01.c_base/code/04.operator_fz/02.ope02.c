#include <stdio.h>

int main(int argc, char *argv[]) {

    int x=70, y=25;

    y = x++ > 70 ? 100 : 0;

    printf("x=%d y=%d\n", x,y); //x=71 y=0

    return 0;
}