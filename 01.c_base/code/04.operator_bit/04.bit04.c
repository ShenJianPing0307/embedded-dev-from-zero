#include <stdio.h>

int main(int argc, char *argv[]) {

    unsigned char x = 75, y = 0173, z;

    z = x ^ y;

    printf("%#x\n", z); // 0x30
    printf("%#o\n", z); // 060

    return 0;

}
/*
 x 十进制
    位权值 128    64   32    16   8   4   2   1
          0      1    0     0    1  0   1   1

 y 八进制
      1     7   3
   001     111    011
          0111 1011
 异或计算  0011 0000

 转成八进制  00 110 000
            060

*/