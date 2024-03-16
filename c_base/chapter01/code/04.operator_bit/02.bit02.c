#include <stdio.h>

int main(int argc, char *argv[]) {

    unsigned char x=0126, y=0xac, z;

    z = x & y;

    printf("z=%#x\n",z);

    return 0;

}
/*
x是八进制，3位一个数字
   1    2     6
  001  010   110   八进制-->二进制
       0101  0110  左边补全

y是十六进制，4位一个数字
       a     c
      1010  1100
&计算
      0000  0100
             4         0x4
*/