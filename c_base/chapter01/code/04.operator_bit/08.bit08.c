#include <stdio.h>

int main(int argc, char *argv[]) {

    int a = 65, b = 0;

    printf("%#x %d\n", a, a); //0x41 65

    // b = a / 16;
    b = a >> 4;
    printf("%#x %d\n", b, b); //0x4 4

    // b = a % 16;
    b = a & 0xf; //与最后的四位做与运算，取数字的最后四位二进制，也就是一位十进制数字
    printf("%#x %d\n", b, b); //0x1 1

    return 0;
}
/*

128 64 32 16 8 4 2 1
  0  1  0  0 0 0 0 1

  0  0  0  0 1 1 1 1     0xf
*/