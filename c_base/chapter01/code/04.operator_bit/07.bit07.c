#include <stdio.h>

/*
如果将 0x4 倒数第 3 位置为 0

 0x4         0100
 加一个数     1011 <-- 0100(~取反) <-- 0001(2<<左移) <-- (y-1)
 最终结果     0000
*/
int main(int argc, char *argv[]) {

    unsigned char x = 0x4, y = 2;

    x = x & (~(2<<(y-1))); // x=0,y=0x2

    printf("x=%#x,y=%#x\n", x, y); // x=0x6,y=0x2

}