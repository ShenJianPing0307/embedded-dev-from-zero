#include <stdio.h>
#include <stdlib.h>

int compare(const void *, const void *);

int main(int argc, char *argv[]) {


    int s[] = {89, 23, 56, 3, 10};
    int n, i;

    n = sizeof(s)/sizeof(int);

    qsort(s, n, sizeof(int), compare);

    for (i = 0; i < n; i++) {

        printf("%d ", s[i]);

    }
    puts("");

    return 0;

}

int compare(const void * p, const void * q) {

    return (*(int *)p - *(int *)q);

}