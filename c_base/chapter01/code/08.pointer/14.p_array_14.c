#include <stdio.h>


int main(int argc, char *argv[]) {

    int a[2][3] = {{1, 4, 6}, {12, 10, 8}};
    int * p[2] = {a[0], a[1]};

    int row, col, sum;

    row = sizeof(a) / sizeof(a[0]);
    col = sizeof(a[0]) / sizeof(int);
    sum = 0;

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {

            // sum += *(p[i] + j);
            // sum += *(a[i] + j);
            // sum += *(*(a+i) + j);
            sum += *(*(p+i) + j);

        }

    }

    printf("sum=%d\n", sum);


    return 0;

}