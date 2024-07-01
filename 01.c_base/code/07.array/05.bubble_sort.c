#include <stdio.h>

int main(int argc, char *argv[]) {

    int a[] = {38, 49, 76, 13, 27, 30, 97};
    int i, j, n, temp;

    n = sizeof(a) / sizeof(int);

    for(i = 0; i < n-1; i++) {

        for(j = 0; j <= n-1-i; j++ ) {

            if(a[j] > a[j+1]) {

                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;

            }

        }

    }

    for(i = 0; i < n-1; i++) {

        printf("%d\n", a[i]);

    }

    return 0;

}