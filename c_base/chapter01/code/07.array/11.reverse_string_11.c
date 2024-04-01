#include <stdio.h>
#include <string.h>

#define N 20

int main(int argc, char *argv[]) {

    char arr[N] = {0};

    int i, n;

    printf("Please input a string:");

//    gets(arr);
    scanf("%s", &arr);
    n = strlen(arr);

    for(i = n-1; i >= 0; i--) {

        putchar(arr[i]);

    }

    putchar('\n');

    return 0;

}