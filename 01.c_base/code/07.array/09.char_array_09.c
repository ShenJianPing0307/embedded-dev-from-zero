#include <stdio.h>

int main(int argc, char *argv[]) {

    char fruits[][20] = {"banana", "apple", "pear"};

    int i, n;

    n = sizeof(fruits) / sizeof(fruits[0]);

    for(i = 0; i < n; i++) {

        printf("%s\n", fruits[i]);

    }

    return 0;

}

/*

banana
apple
pear

*/