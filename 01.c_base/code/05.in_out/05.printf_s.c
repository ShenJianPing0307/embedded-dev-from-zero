#include <stdio.h>


int main(int argc, char *argv[]) {

    static char a[] = "Hello, World!";

    printf("%s\n%15s\n%10.5s\n%2.5s\n%.3s\n", a,a,a,a,a);

    return 0;

}
/*
输出：

Hello, World!
  Hello, World!
     Hello
Hello
Hel

*/