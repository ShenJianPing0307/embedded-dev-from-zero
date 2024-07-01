#include <stdio.h>

char * del_space(char * s);

int main(int argc, char * argv[]) {

    char * r;
    char str[] = "hello world !";

    r = del_space(str);

    printf("---%s---", r);
}

char * del_space(char * s) {

    char * p = s;
    char * s1 = s; // s1记住初始位置

    while (*s) {

        if (*s == ' ') {

            s++;

        } else {
            *p = *s;
            s++;
            p++;
        }

    }

    *p = '\0';
    return s1;
}