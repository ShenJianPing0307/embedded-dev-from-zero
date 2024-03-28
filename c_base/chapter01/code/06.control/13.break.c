#include <stdio.h>
#include <math.h>


int main(int argc, char *argv[]) {

    int n, temp;
    int i;

    printf("please input:");
    scanf("%d", &n);

    temp = sqrt(n);
    i = 2;

    while (i <= temp) {

        if (n % i == 0) {
            break;
        }
        i++;
    }

    if (i <= temp) {
        printf("%d not paas\n", n);
    } else {
        printf("%d paas\n", n);
    }

    return 0;

}