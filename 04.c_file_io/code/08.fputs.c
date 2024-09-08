#include <stdio.h>

/*
* 将缓冲区内容写入到文件
*/
int main(int argc, char *argv[]) {

    FILE *fp;
    int ret;
    char buff[] = "hello world";
    if ((fp = fopen("1.txt", "a+")) == NULL) {
        perror("fopen");
        return -1;
    }

    if ((ret = fputs(buff, fp)) == -1) {
        perror("fputs");
        fclose(fp);
        return -1;
    }

    printf("fputs success\n");

    return 0;

}