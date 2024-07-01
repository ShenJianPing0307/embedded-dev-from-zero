#include <stdio.h>
#include <string.h>

#define N 10

int main(int argc, char *argv[]) {

    char src[] = "world";
    char dest[] = "HELLO";
    // char usrc[] = "World";
    //char ch = 'o';
    char subs[] = "rld";

    // strncpy(dest, src, 3);
    // printf("%s\n", dest); // worLO

    // strncat(dest, src, 3);
    // puts(dest); // HELLOwor

    // printf("%d\n", strcasecmp(src, usrc)); // 0
    // printf("%d\n", strncmp(src, usrc, 3)); // 1

    //printf("%d\n",strchr(src, ch)-src);

    printf("%d\n",strstr(src, subs)-src);

    return 0;

}
