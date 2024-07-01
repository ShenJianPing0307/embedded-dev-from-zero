#include <stdio.h>

int main(int argc, char *argv[]) {

    int x;
    char ch;

    scanf("%d", &x);
    scanf(" %c", &ch); // 或者 scanf("%*c%c", &ch);

    return 0;

}