#include <stdio.h>

int main(int argc, char *argv[]) {

    int c;
    printf("Enter a character:");
    c = getchar();
    printf("%c--%d->hex%x\n", c,c,c);

    return 0;

}
/*
输出：

Enter a character:B
B--66->hex42

*/