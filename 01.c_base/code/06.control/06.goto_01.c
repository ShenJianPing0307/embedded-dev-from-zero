#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 0;
    int sum = 0;
_loop:
    if (i <= 100) {
        sum += i;
        i++;
        goto _loop;
    }

    printf("1+2+3...+100=%d\n", sum);

    return 0;
}