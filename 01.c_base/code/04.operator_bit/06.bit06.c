#include <stdio.h>

/*
如果将 0x4 倒数第 2 位置为 1

 0x4         0100
 加一个数     0010(1<<(y-1)) <-- 0001 <-- 1(十进制1) <-- (y-1)
 最终结果     0110
*/
int main(int argc, char *argv[]) {

    unsigned char x = 0x4, y = 2;

    x = x | (1<<(y-1));

    printf("x=%#x,y=%#x\n", x, y); // x=0x6,y=0x2

}