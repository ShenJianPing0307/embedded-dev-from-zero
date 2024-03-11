#include <stdio.h>

int main(int argc, char *argv[]) {

    int a=5, b=6;

    if (! (a > (b-1)))
        printf("false\n"); //false
    else
        printf("true\n");

    return 0;

}