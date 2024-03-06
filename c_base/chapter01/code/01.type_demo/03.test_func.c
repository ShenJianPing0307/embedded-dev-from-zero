#include <stdio.h>

// __FILE__, __FUNCTION__, __LINE__实现代码跟踪调试
int main() {

    int p=1, i=2;

    while (i <= 10) {
        p = p + i;
        i++;
    }
    printf("%s,%s,%d,p=%d\n", __FILE__, __FUNCTION__, __LINE__, p);
    return 0;
}