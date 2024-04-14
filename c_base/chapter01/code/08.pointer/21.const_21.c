#include <stdio.h>

int main(int argc, char *argv[]) {

    int m = 10;
    const int * p;
    p = &m; // right
    *p++; // error
    return 0;

}