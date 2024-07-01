#include <stdio.h>
#include <math.h>


int main(int argc, char *argv[]) {

    for (int i = 1; i <= 1000; i++) {

        if (i % 3 == 0) {
            continue;
        }

        printf("%d\n", i);

    }

    return 0;

}