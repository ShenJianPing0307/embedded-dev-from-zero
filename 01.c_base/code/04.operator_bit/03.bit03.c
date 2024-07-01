#include <stdio.h>

int main(int argc, char *argv[]) {

    unsigned char x=076, y=0x89, z;

    z = x|y;

    printf("%#x\n", z); //0xbf

    return 0;

}
/*
x是八进制，三位表示
      7      6
     111    110
    0011    1110
y是十六进制，四位表示
     8      9
   1000    1001
运算
   1011    1111
    B       F
*/