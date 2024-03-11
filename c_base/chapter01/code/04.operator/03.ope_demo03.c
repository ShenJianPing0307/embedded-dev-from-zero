#include <stdio.h>

int main(int argc, char *argv[]) {

    int a=5, b=6, c;

    c = a > (b-1);
    printf("c=%d\n", c); // 0

    c = (a+1) == b;
    printf("c=%d\n", c); // 1

    c = a >= (b-2);
    printf("c=%d\n", c); // 1

    return 0;

}