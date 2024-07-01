#include <stdio.h>

int main(int argc, char *argv[]) {

    int a[] = {5, 8, 7, 6, 2, 7, 3};
    int y, * p = &a[1];

    y = (*--p)++;

    printf("%d\n", y); // 5
    printf("%d\n", a[0]); // 6

    return 0;

}
