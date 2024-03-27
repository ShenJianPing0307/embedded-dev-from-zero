#include <stdio.h>

int main(int argc, char *argv[]) {

    enum weekday
    {sun, mon, tue, wed} a;

    a = wed;

    switch (a) {
    case 1:
        printf("1\n");
        break;
    case 2:
        printf("2\n");
        break;
    case 3:
        printf("3\n");
        break;
    default:
        printf("not 1 2 3\n");
    }

    return 0;

}