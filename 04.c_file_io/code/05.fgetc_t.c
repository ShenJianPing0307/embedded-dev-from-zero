#include <stdio.h>

int main(int argc, char *argv[]) {
    int ch;
    FILE *fp;
    if ((fp = fopen("1.txt", "r")) == NULL) {
        perror("fopen");
        return -1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        printf("ch=%c\n", ch);
    }
    return 0;
}