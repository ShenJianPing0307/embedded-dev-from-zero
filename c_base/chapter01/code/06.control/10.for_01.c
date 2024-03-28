#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 1;
    int sum = 0;

    for (;i <= 100; i++) {

        sum += i;

    }

    printf("1+2+3+...+100=%d\n", sum);

}