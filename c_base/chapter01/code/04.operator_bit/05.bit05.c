#include <stdio.h>


int main(int argc, char *argv[]) {

    unsigned char a=0xe4, b;

    b = a<<3;

    printf("b=%#x\n", b); // 0x20

    return 0;

}

/*

    e   4
   1110   0100
<< a 左移位3位存入b的情况, 前边三个1被移除，后面补0
   0010   0000
    2      0
*/