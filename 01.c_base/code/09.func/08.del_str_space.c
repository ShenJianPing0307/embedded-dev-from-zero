#include <stdio.h>

void del_space(char * s1);

int main(int argc, char *argv[]) {

    char s[] = "s lk h n";

    del_space(s);

    puts(s);

}

void del_space(char * s1) {

    char * s2 = s1;

    while (*s1) {
        if (*s1 == ' ') {
            s1++;
        } else {
            *s2 = *s1;
            s1++;
            s2++;
        }

    }
    *s2 = '\0';

}