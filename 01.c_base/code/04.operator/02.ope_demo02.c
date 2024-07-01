#include <stdio.h>

int main(int argc, char *argv[]) {

    int x=5, y=9, z;
    z = ++x;
    printf("z=%d x=%d\n", z, x); // 6 6
    z = x++;
    printf("z=%d x=%d \n", z, x); // 6 7
    z = --x;
    printf("z=%d x=%d\n", z, x); // 6 6
    z = x--;
    printf("z=%d x=%d\n", z, x); // 6 5
    z = ++x + y++; // 6 + 9 = 15  x=6 y=10
    printf("z=%d\n", z); // 15
    z = --x + y++; // 5 + 10 = 15 x=5 y=11
    printf("z=%d\n", z); // 15
    z = ++x + y--; // 6 + 11 = 17 x=6 y=10
    printf("z=%d\n", z); // 17

    return 0;

}