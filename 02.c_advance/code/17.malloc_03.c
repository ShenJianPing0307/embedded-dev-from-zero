#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {

    // char *p; //没有初始化
    char *p;
    char s[] = "well"; // well\0
    p = s;

    strcpy(p, "welcome"); // welcome超出数组字节数

    return 0;
}