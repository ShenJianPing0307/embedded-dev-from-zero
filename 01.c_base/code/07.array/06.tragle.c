#include <stdio.h>

/*

思路：
1、打印正方形
2、打印出一半（col <= row）

1 0
1 1 0
1 2 1

*/

int main(int argc, char *argv[]) {


    int row, col;
    int triangle[10][10] = {{0}};

    for(row = 0; row < 10; row++) {

        triangle[row][0] = 1; // 第一列设置为1

        for(col = 1; col <= row ; col++) {

            triangle[row][col] = triangle[row-1][col-1] + triangle[row-1][col];

        }

    }

    for(row = 0; row < 10; row++) {

        for(col = 0; col <= row; col++) {

                printf("%d\t",triangle[row][col]);


        }

        putchar('\n');
    }

    return 0;

}