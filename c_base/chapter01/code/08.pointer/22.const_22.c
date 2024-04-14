#include <stdio.h>

int main(int argc, char *argv[]) {

    int m = 10;
    int * const p;
    p = &m; // error
    *p = 30; // right
    return 0;

}