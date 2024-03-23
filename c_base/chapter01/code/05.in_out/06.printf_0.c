#include <stdio.h>

int main(int argc, char *argv[]) {

    int a = 1234;
    float f = 123.456;

    printf("%08d\n", a);
    printf("%010.2f\n", f);
    printf("%0+8d\n", a);
    printf("%0+10.2f\n", f);

    return 0;

}
/*
输出：

00001234
0000123.46
+0001234
+000123.46

*/