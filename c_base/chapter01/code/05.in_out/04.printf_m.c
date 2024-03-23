#include <stdio.h>

/*

m.n格式

*/

int main(int argc, char *argv[]) {

    int a = 1234;
    float f = 123.456;
    char ch = 'a';

    printf("%8d, %2d\n", a, a);
    printf("%f, %8f, %8.1f, %.2f\n", f,f,f,f);
    printf("%3c\n", ch);

    return 0;

}
/*
输出：

    1234, 1234
123.456001, 123.456001,    123.5, 123.46
  a

*/