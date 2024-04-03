#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char s[10] = {'A','\0','B','C','D','\0','E'};
    char s1[] = "\t\v\\\0we\n";
    char s2[] = "\x69\141\n";

    printf("s:%d,s1:%d,s2:%d\n", strlen(s), strlen(s1), strlen(s2));

    return 0;

}
/*
s:1,s1:3,s2:3
*/
