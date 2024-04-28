#include <stdio.h>

void swap(int *, int *);

int main(int argc, char *argv[]) {

    int a = 1, b = 2;

    swap(&a, &b);

    printf("a=%d, b=%d\n", a, b); // a=2, b=1

}

void swap(int * a, int * b) {

    int t;

    t = *a;
    *a = *b;
    *b = t;

}