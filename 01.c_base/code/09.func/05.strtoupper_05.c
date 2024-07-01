#include <stdio.h>

int str_func(char *);


int main(int argc, char *argv[]) {
    char s[] = "Hello";
    int n;

    n = str_func(s);
    printf("n=%d %s\n", n, s);

    return 0;
}

int str_func(char * p) { // char * p = s;
    int num = 0;

    while (*p != '\0') { // while (*p)

        if (*p <= 'z' && *p >= 'a') {
            num++;
            *p -= ' ';
        }

        p++;
    }
    return num;
}

