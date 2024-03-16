#include <stdio.h>


int main(int argc, char *argv[]) {

    int count=0, sum=0;

    while (count++ < 100) {

       sum += count;

    }
    printf("sum=%d\n", sum); // sum=5050

    return 0;
}