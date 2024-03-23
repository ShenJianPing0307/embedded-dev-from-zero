#include <stdio.h>

int main(int argc, char *argv[]) {

    int a = 567;
    printf("%d\n", a);

    a = 255;
    printf("%x\n", a);

    a = 65;
    printf("%o\n", a);

    a = 567;
    printf("%u\n", a);

    a = 65;
    printf("%c\n", a);

    return 0;

}
/*
输出：

567
ff
101
567
A

*/