#include <stdio.h>

int main(int argc, char *argv[]) {


    int a[3][4] = {{1,22,56,2},{33,89,9,25},{31,10,3,8}};
    int n, m, i, j, row, col;

    n = sizeof(a) / sizeof(a[0]);
    m = sizeof(a[0]) / sizeof(int);
    row = 0;
    col = 0;

    for(i = 0 ;i < n; i++) {

        for(j = 0; j < m; j++) {

            if(a[i][j] > a[row][col]) {
                row = i;
                col = j;
            }

        }

    }
    printf("%d-%d-%d\n", row, col,a[row][col]);

    return 0;

}