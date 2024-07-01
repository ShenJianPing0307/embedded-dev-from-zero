#include <stdio.h>

int main(int argc, char *argv[]) {

    int x = -126;
    int * p;
    p = &x;

    printf("x=%d,x=%d\n", x, *p);
    printf("p=%p\n",p);
    printf("&p=%p\n", &p);

    return 0;

}
/*
x=-126,x=-126
p=0xbfcfe424
&p=0xbfcfe428
*/