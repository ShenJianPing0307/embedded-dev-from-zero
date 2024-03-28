#include <stdio.h>

int func() {

    return 10;
}

int main(int argc, char *argv[]) {

    int res;

    res = func();

    printf("%d\n", res);

    return 0;

}