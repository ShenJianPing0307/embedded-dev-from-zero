#include <stdio.h>
#include <string.h>

#define N 30

int main(int argc, char *argv[]) {

    char s1[N] = {'A','B','\0'};
    char s2[] = "hello";

    strcat(s1, s2);

    puts(s1);
    puts(s2);

    return 0;

}

/*
ABhello
hello
*/