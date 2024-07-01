#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
gcc 02.if_02.c -lm
*/
int main(int argc, char *argv[]) {

    float a, b, c;
    float p;
    float area;

    scanf("%f %f %f", &a, &b, &c);

    if( a + b <= c || a + c <= b || b + c <= a ||  abs(a - b) >= c || abs(a - c) >= b || abs(b - c) >= a) {
        printf("invalid input\n");
    } else {
        p = (a+b+c) / 2;
        area = sqrt(p * (p-a) * (p-b) * (p-c));
        printf("%.2f, %.2f, %.2f ---> %.2f\n", a, b, c, area);
    };

    return 0;

}