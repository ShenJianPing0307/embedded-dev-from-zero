#include <stdio.h>


int main(int argc, char *argv[]) {

    int a[] = {3, 1, 10, 9, 8};
    int n, i;
    void * p;

    p = a;
    n = sizeof(a) / sizeof(int);

    for(i=0; i < n; i++){

        printf("%d\n", *((int *)p + i));

    }

    return 0;

}