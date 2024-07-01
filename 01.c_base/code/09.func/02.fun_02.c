#include <stdio.h>

// 全局变量
double y = 2;
int m =2;

double cal(double x, int n) {

    double res = 1;
    for (int i = 1; i <= n;  i++) {
        res *= res * x;
    }
    return res;

}

int main(int argc, char *argv[]) {

    double res;

    res = cal(y, m);

    printf("res=%lf\n", res);

}