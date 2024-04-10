#include <stdio.h>

int main(int argc, char *argv[]) {

    int a[3][3] = {{1, 2, 3}, {6, 9, 0}, {7, 5, 12}};
    int *p, i, n;

    n = sizeof(a) / sizeof(int);

    p = a[0]; // &a[0][0]

    printf("%p %p %d %d\n", p, p+1, *p, *(p+1)); // 0xbfa524e8 0xbfa524ec 1 2
    printf("%p %p\n", a, a+1); // 0xbfa524e8 0xbfa524f4

    for (i = 0; i < n; i++) {

        printf("%d ", *(p+i)); // 1 2 3 6 9 0 7 5 12

    }
    puts("");

    return 0;


}