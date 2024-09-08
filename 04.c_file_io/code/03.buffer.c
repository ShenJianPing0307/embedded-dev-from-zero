#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int i;
    for(i = 0; i < 1025; i++) {
         printf("a"); //缓冲区满了，会刷新进行内容输出
    }

    while (1) {
    sleep(1);
    }

    return 0;

}