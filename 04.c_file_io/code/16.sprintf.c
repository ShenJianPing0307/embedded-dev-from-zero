#include <stdio.h>

int main(int argc, char *argv[]) {

    char buf[100] = {0};
    int year=2024;
    int month=9;
    int day=15;

    int syear;
    int smonth;
    int sday;

    sprintf(buf, "%d-%d-%d", year, month, day);
    printf("%s\n", buf);

    sscanf(buf, "%d-%d-%d", &syear, &smonth, &sday);
    printf("%d %d %d\n", syear, smonth, sday);

    return 0;

}