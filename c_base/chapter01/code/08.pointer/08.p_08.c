#include <stdio.h>

int main(int argc, char *argv[]) {

    int a[] = {1, 6, 9, 12, 89, 23, 52};

    int *p, *q, t, n;

    p = a;
    n = sizeof(a) / sizeof(int);
    q = &a[n-1];

    while(p <= q) {

        t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;

    }

    for(t = 0; t < n; t++) {

        printf("%d\t", a[t]);

    }
    puts("");

}