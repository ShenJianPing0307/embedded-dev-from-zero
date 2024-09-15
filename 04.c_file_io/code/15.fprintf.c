#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    int year=2024;
    int month=9;
    int day=15;

    if((fp=fopen("ftest.txt", "w")) == NULL) {
        perror("fopen");
        return 0;
    }
    fprintf(fp, "%d-%d-%d\n", year, month, day);

    fclose(fp);

}