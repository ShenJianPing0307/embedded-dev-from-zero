#include <stdio.h>


int main(int argc, char *argv[]) {

    int a;
    char c;
    float f;

    scanf("%d%c%f", &a,&c,&f);

    printf("a=%d, c=%c f=%f\n", a, c, f);

    return 0;

}
/*

输入：1234a123o.26
输出：a=1234, c=a f=123.000000

*/