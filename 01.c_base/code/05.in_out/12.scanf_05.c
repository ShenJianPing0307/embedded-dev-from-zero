#include <stdio.h>

int main(int argc, char *argv[]) {

    int x;
    char ch;

    scanf("%d", &x);
    scanf("%c", &ch);

    printf("x=%d, ch=%d\n", x, ch);

    return 0;

}
/*

输入：5
输出：x=5, ch=10

上面输入5后回车，本意是在输入ch的值，但是ch这时会接收回车
程序会直接结束

*/