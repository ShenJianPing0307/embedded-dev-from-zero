#include <stdio.h>

int main(int argc, char *argv[]) {

    unsigned char x = 0x17, y;

    y = ~x;

    printf("%#x\n", y); // 0xE8

    return 0;

}