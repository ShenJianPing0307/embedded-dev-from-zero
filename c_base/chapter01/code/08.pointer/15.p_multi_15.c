#include <stdio.h>


int main(int argc, char *argv[]) {

    int m = 10;
    int * p;
    int * * q;

    p = &m;
    q = &p;

    printf("%p %p\n", p, &m); // 0xbfb9c9b0 0xbfb9c9b0
    printf("%p %p\n", q, &p); // 0xbfb9c9b4 0xbfb9c9b4
    printf("%d %d %d\n", m, *p, **q); // 10 10 10

    return 0;

}