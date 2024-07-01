#include <stdio.h>
#include <string.h>

#define N 30

int main(int argc, char *argv[]) {

    char src[] = "hello";
    char dest[N];
/*
    strcpy(dest, src);

    printf("%s\n", dest);
*/

    int i, n;
    i = 0;
    n = sizeof(src) / sizeof(char);

    while (i < n) {

        dest[i] = src[i];
        i++;

    }
    puts(dest);

    return 0;

}