#include <stdio.h>

int main(int argc, char *argv[]) {
    char ch1 = 'A', ch2;
    int a;

    ch2 = ch1 + 32; // ch2 = ch1 + ' ';
    printf("%c %c\n", ch1, ch2);
    printf("%d %d\n", ch1, ch2);

    ch1 = '0';
    a = ch1 - 48;
    printf("%c %c\n", ch1, ch2);
    printf("%d %d\n", ch1, ch2);
    printf("%d\n", a);

    return 0;
}
/*
A a
65 97

0 a
48 97
0
*/