#include <stdio.h>

int main(int argc, char *argv[]) {

    int a[5] = {10, 2, 5, 56, 80};

    int *p = NULL, *q;

    printf("%d %p\n", p, p); // 0 (nil)

    p = a; // &a[0];
    q = p++;

    printf("%p %p\n", p, q); // 0xbfcee30c 0xbfcee308
    printf("%d %d\n", *p, *q); // 2 10

    return 0;

}