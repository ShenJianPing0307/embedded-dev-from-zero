#include <stdio.h>

int main(int argc, char *argv[]) {

    if (1) {
        int a; //没有初始化，随机值
        printf("a=%d\n", a);
    }
    // printf("out if:a=%d\n", a); 变量作用域，在局部变量作用域中
    return 0;
}