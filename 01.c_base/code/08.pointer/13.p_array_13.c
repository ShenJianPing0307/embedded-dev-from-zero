#include <stdio.h>


int main(int argc, char *argv[]) {

    int a[2][3] = {{1, 4, 6}, {12, 10, 8}};
    int * p[2];

    p[0] = a[0];
    p[1] = a[1];

    printf("%d\n", a[0][1]); // 4
    printf("%d\n", *(a[0]+1)); // 4
    printf("%d\n", *(p[0]+1)); // 4

    printf("%d\n", *(p[1]+2)); // 8

    return 0;

}