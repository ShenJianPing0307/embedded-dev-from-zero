#include <stdio.h>


int get_num() {
    int sum;

    for (int i=0; i < 100; i++) {
        sum += i;
    }
    return sum;

}

int main() {

    int ret;

    ret = get_num();

    printf("%d\n", ret);

    return 0;
}


