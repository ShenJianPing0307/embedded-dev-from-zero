#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char s1[] = "abc";
    char s2[] = "ad";

    printf("%d\n", strcmp(s1, s2)); // -1

    return 0;

}