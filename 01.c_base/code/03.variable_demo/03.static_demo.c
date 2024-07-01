#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 1;

    while (i < 5) {
        //int a = 0;  每次循环a被重新赋值为o,所以a=1
        //static int a = 0; 每次循环a上次的值都在，所以a=1,2,3,4，类似全局变量
        a++;
        printf("a=%d\n", a);
        i++;
    }

}