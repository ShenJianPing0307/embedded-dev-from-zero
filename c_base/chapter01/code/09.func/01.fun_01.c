#include <stdio.h>

double cal(double x, int n) {

    double res = 1;
    for (int i = 1; i <= n;  i++) {
        res *= res * x;
    }
    return res;

}


int main(int argc, char *argv[]) {

    double x = 2, res;
    int n =2;
    res = cal(x, n);

    printf("res=%lf\n", res);

}