#include <stdio.h>

int main() {
    int a = 0x12345678;
    float b= 3.5e-10;

    printf("%d %x %o\n", a, a, a);
    printf("%e %f\n", b, b);

    return 0;

}