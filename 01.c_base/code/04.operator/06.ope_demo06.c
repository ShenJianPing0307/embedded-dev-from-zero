#include <stdio.h>


int main(int argc, char *argv[]) {

    int x=5, y=18, z;

    z = (x>=5) && (y<20);
    printf("(x>=5) && (y<20) z=%d\n", z); // 1

    z = ((x+1)>=0) && (y<17);
    printf("z =((x+1)>=0) z=%d\n", z); // 0

    z = ((x-8)>=0) && (y==18);
    printf("((x-8)>=0) && (y==18) z=%d\n", z); // 0

    z = ((x>=5)) || (y<20);
    printf("((x>=5)) || (y<20) z=%d\n", z); //1

    return 0;
}