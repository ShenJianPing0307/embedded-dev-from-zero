#include <stdio.h>

int main(int argc, char *argv[]) {

    int a[] = {1, 6, 9, 12, 89, 23, 52};

    int *p, i, n;

    p = a;
    n = sizeof(a) / sizeof(int);

    for(i = 0; i < n; i++) {

        printf("%d %d %d %d\n", a[i], *(p+i), *(a+i), p[i]);

    }

    return 0;

}
/*

1 1 1 1
6 6 6 6
9 9 9 9
12 12 12 12
89 89 89 89
23 23 23 23
52 52 52 52

*/