#include <stdio.h>

int main(int argc, char *argv[]) {

    int a[5] = {10, 2, 5, 56, 80};

    int * p, * q;

    p = a; // &a[0];
    q = &a[3];

    printf("%p %p\n", p, q); // 0xbfcde808 0xbfcde814
    printf("%d %d\n", *p, *q); // 10 56
    printf("q-p=%d\n", q-p); // q-p=3

    return 0;

}