#include <stdio.h>

double cal(double, int);

int main(int argc, char *argv[]) {

    double x = 2, res;
    int n =2;

    printf("main &x=%p, &n=%p\n", &x, &n); // &x=0xbf81f9e8, &n=0xbf81f9e4

    res = cal(x, n);

    printf("res=%lf\n", res);

}

double cal(double x, int n) { // double x = x; int n =n;

    double res = 1;
    printf("cal &x=%p, &n=%p\n", &x, &n); // &x=0xbf81f998, &n=0xbf81f9c8
    for (int i = 1; i <= n;  i++) {
        res *= res * x;
    }
    return res;

}


