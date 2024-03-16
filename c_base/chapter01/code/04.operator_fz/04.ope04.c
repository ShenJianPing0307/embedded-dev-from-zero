#include <stdio.h>

int main(int argc, char *argv[]) {

    printf("bool-->%d", sizeof(_Bool));

    printf("char-->%d", sizeof(char));

    printf("int-->%d", sizeof(int));

    printf("short-->%d", sizeof(short));

    printf("long-->%d", sizeof(long));

    printf("float-->%d", sizeof(float));

    printf("double-->%d", sizeof(double));

    return 0;

}