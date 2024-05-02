#include <stdio.h>

int power(int);

int main(int argc, char * argv[]) {

    int n, ret;

    printf("请输入：");
    scanf("%d", &n);

    ret = power(n);

    printf("ret=%d\n", ret);


}

int power(int n) {

    int ret = 1;

    while (n) {

        ret *= n;
        n -= 1;

    }

    return ret;

}