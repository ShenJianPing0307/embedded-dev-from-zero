#include <stdio.h>

int main(int argc, char *argv[]) {

    int m = 10;
    const int * const p = &m;

    p++; // error
    *p++; // error
    return 0;

}