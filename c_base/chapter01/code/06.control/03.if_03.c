#include <stdio.h>

int main(int argc, char *argv[]) {

    float score;

    printf("please input your score:");
    scanf("%f", &score);

    if (!(score >= 0 && score <= 100)) {
        printf("not in [0, 100]\n");
    } else if (score >= 90) {
        printf("A-excellent\n");
    } else if (score >= 70) {
        printf("B-good\n");
    } else if (score >= 60) {
        printf("C-ok\n");
    } else {
        printf("D-not paas\n");
    }

    return 0;

}