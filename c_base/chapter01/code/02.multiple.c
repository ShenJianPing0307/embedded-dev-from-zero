#include <stdio.h>

int main() {
    // 计算1-10相乘
    int p = 1, i = 2;
    while (i<=10) {
        p = p * i;
        i++;
    }
    printf("p=%d\n", p);
    return 0;
}