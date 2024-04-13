#include <stdio.h>

int main(int argc, char *argv[]) {

    int a[] = {3, 6, 9};
    int * p[2] = {&a[0], &a[1]}; // int * -- p[0] p[1]

    int ** q;
    q = p;

    printf("%p %p\n", &a[0], &p);

    printf("%d %d\n", a[0], a[1]); // 3 6
    printf("%d %d\n", *p[0], *p[0]); // 3 3

    printf("%d %d %d\n", a[0], *p[0], **q); // 3 3 3
    printf("%d %d %d\n", a[1], *p[1], **(q+1)); // 6 6 6

    return 0;

}