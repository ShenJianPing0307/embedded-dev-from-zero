#include <stdio.h>

/*
* 从文件中读出字符
*/
int main(int argc, char *argv[]) {

    FILE *fp;
    char *ret;
    char buff[100];

    if ((fp = fopen("1.txt", "a+")) == NULL) {
        perror("fopen");
        return -1;
    }

    if ((ret = fgets(buff, 5, fp)) == NULL) {
        perror("fgets");
        fclose(fp);
        return -1;
    }

    printf("buff=%s\n", buff);

    return 0;

}