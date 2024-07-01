#include <stdio.h>

extern int global_a; //外部文件的引用

int main(int argc, char *argv[]) {

    printf("global_a=%d\n", global_a);

    return 0;
}