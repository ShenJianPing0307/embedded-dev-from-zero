#include <stdio.h>


int main(int argc, char *argv[]) {

    int a[3][3] = {{1, 2, 3}, {6, 9, 0}, {7, 5, 12}};

    int (*p)[3], i, j, row, col;

    p = a;

    row = sizeof(a) / sizeof(a[0]);
    col = sizeof(a[0]) / sizeof(int);

    printf("%d %d\n", row, col);

    printf("%p %p %p\n",&a[0], a[0], &a[0][0]); // a[0]存放的内容就是 a[0][0] 的地址, 所以下面就是 *(*(p+i)+j)
    printf("%p %p %p\n",&a[1], a[1], &a[1][0]);

    for (i = 0; i < row; i++) {

        for (j = 0; j < col; j++) {

            printf("%d %d %d %d", a[i][j], p[i][j], *(*(p+i)+j), *(*(a+i)+j));

        }

        puts("");

    }


    return 0;

}