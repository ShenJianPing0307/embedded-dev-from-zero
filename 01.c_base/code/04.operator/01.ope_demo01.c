#include <stdio.h>

int main(int argc, char *argv[]) {

    int a=15, b=8, c;

    c = a + b;
    printf("c=%d\n", c);
    c = a - b;
    printf("c=%d\n", c);
    c = a * b;
    printf("c=%d\n", c);
    c = a / b;
    printf("c=%d\n", c);
    c = a % b;
    printf("c=%d\n", c);

    return 0;
}