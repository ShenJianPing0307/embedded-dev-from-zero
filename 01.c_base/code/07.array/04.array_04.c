#include <stdio.h>

int main(int argc, char *argv[]) {

    int a[5] = {};
    int b[5] = {1,2,3};

    for(int i = 0; i < 5; i++) {

        printf("a数组-%d-%d\n", i, a[i]);

    }

    for(int i = 0; i < 5; i++) {

        printf("b数组-%d-%d\n", i, b[i]);

    }

    return 0;

}
/*
a数组-0-0
a数组-1-0
a数组-2-0
a数组-3-0
a数组-4-0

b数组-0-1
b数组-1-2
b数组-2-3
b数组-3-0
b数组-4-0
*/