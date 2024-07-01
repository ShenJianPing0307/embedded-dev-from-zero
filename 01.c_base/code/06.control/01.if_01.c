#include <stdio.h>

int main(int argc, char *argv[]) {

    float a = 4, b = 5, c = 2, t;
    if(a >b) {
        t = a;
        a = b;
        b = t;
    };

    if(a > c) {
        t = a;
        a = c;
        c = t;
    };

    if(b > c) {
        t = b;
        b = c;
        c = t;
    };

    printf("%5.2f, %5.2f, %5.2f\n", a, b, c); //  2.00,  4.00,  5.00

    return 0;
}