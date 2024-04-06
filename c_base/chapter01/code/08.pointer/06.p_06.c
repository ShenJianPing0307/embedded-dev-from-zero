#include <stdio.h>

int main(int argc, char *argv[]) {

    int i, * p, a[7];
    p = a;

    for (i = 0; i < 7; i++) {
        scanf("%d", p++);
    }
    puts("");

    p = a;
    for (i = 0; i < 7; i++) {
        printf("%d\n", *p);
        p++;
    }

    return 0;

}