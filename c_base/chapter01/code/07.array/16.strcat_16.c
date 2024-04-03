#include <stdio.h>
#include <string.h>

#define N 30

int main(int argc, char *argv[]) {

    char s1[N] = {'A','B','\0'};
    char s2[] = "Turbo", s3[]="";

    strcpy(s1, s2);
    strcat(s1, s3);

    puts(s1);

    return 0;

}

/*
Turbo
*/