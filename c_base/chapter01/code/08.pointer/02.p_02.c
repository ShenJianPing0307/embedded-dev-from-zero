#include <stdio.h>

int main(int argc, char *argv[]) {

    int a = 10;
    int * p;
    p = &a;

    printf("p-2=%p, p=%p, p+2=%p\n", p-2, p, p+2); // p-2=0xbfc6f55c, p=0xbfc6f564, p+2=0xbfc6f56c

    return 0;

}