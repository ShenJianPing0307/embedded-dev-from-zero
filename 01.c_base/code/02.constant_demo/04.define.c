#include <stdio.h>

#define ONE 1
#define TWO ONE + ONE

int main(int argc, char *argv[]) {

    int a = 10, b = 20, c;
    c = ONE + TWO * b + a; // 1 + 1 + 1 * 20 + 10 = 32
    printf("%d\n", c);

    return 0;
}
/*
在预编译阶段，只会进行变量替换
通过 gcc -E 04.define.c -o 04.define.i
然后查看 04.define.i 文件

通过添加括号的方式提高优先级
#include <stdio.h>

#define ONE 1
#define TWO ((ONE) + (ONE))  // 添加括号

int main(int argc, char *argv[]) {

    int a = 10, b = 20, c;
    c = ONE + TWO * b + a; // 1 + 1 + 1 * 20 + 10 = 32
    printf("%d\n", c);

    return 0;
}
*/