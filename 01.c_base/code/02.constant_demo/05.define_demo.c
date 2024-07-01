/*
一个水分子的质量约为3.0*10-23g，
1夸脱水大约有950g，
编写一个程序，要求输入水的夸脱数，
然后显示这么多水中包含多少水分子。
*/
#include <stdio.h>

#define MASS 3.0e-23
#define WEIGHT 950

int main(int argc, char *argv[]) {

    float n, total;

    printf("input n:");
    scanf("%f", &n);

    total = n * WEIGHT / MASS;

    printf("%e\n", total);

    return 0;
}