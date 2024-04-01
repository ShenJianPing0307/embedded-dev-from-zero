#include <stdio.h>

int main(int argc, char *argv[]) {

    char fruits[][20] = {"banana", "apple", "pear"};

    int i, j, n, m;

    n = sizeof(fruits) / sizeof(fruits[0]);
    m = sizeof(fruits[0]) / sizeof(char);

    for(i = 0; i < n; i++) {

        for(j = 0; j < m; j++) {

            putchar(fruits[i][j]);

        }

        putchar('\n');

    }


    return 0;

}