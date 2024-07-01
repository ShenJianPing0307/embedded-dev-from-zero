#include <stdio.h>

int main(int argc, char *argv[]) {

    int x;
    char ch;

    scanf("%d", &x);
    getchar();
    ch = getchar();

    printf("x=%d, ch=%d\n", x, ch);

    return 0;

}
/*
输入：
5
a
输出：
x=5, ch=97

*/