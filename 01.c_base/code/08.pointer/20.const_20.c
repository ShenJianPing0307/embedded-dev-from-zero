#include <stdio.h>

int main(int argc, char *argv[]) {

    const int m = 10;
    m++; // error: increment of read-only variable ‘m’
    printf("m=%d\n", m);

    return 0;

}