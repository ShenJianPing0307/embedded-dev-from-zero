#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    int year;
    int month;
    int day;

    if((fp=fopen("ftest.txt", "r")) == NULL) {
        perror("fopen");
        return 0;
    }

    fscanf(fp, "%d-%d-%d", &year, &month, &day);
    printf("%d %d %d\n", year, month, day);

    fclose(fp);

    return 0;

}