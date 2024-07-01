#include <stdio.h>

int main(int argc, char *argv[]) {

    int a[] = {1, 2, 3, 4, 5};

    // printf("%d\n", a);  error

    for(int i = 1; i < 5; i++ ) {
        printf("%d\n", a[i]);
    }

    return 0;

}