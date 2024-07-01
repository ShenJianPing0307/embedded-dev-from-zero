#include <stdio.h>

#define N 100

int main(int argc, char *argv[]) {

    char s1[] = "hello";
    char s2[] = "world";
    char s[N];

    char * p, * q;
    p = s1;
    q = s2;

    int i = 0, j = 0, n = sizeof(s2) / sizeof(char);

    while (*(p+i) != '\0') {

        s[i] = *(p+i);
        i += 1;
    }

    for (j = 0;j < n;j++) {
        s[i] = *(q+j);
        i++;
    }

    printf("%s\n", s); // helloworld

    return 0;

}