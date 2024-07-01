#include <stdio.h>

int main(int argc, char *argv[]) {

    static int a[5];

    for(int i = 0; i < 5; i++) {

        printf("%d-%d\n", i, a[i]);

    }

    return 0;

}
/*
0-0
1-0
2-0
3-0
4-0
*/