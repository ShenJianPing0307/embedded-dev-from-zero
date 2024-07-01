#include <stdio.h>

int main(int argc, char *argv[]) {

    int m = 10;
    double n = 3.14;
    void * p, * q;

    p = &m; // (void *)&m
    printf("%d %d\n", m, *(int *)p); // 10 10

    q = &n; // (void *)&n
    printf("%.2lf %.2lf\n", n, *(double *)q); // 3.14 3.14
    printf("%p\n", p);
}