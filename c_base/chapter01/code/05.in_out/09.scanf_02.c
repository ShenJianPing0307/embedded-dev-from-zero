#include <stdio.h>

int main(int argc, char *argv[]) {

    int a, b;

    scanf("%2d %*3d %2d", &a, &b);

    printf("a=%d, b=%d\n", a, b);

    return 0;

}

/*

输入：12 345 67
输出：a=12, b=67

*/