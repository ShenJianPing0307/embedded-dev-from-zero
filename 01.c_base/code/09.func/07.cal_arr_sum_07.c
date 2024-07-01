#include <stdio.h>

int array_sum(int data[], int n);

int main(int argc, char *argv[]) {

    int a[] = {10, 2, 5, 89, 36, 6};
    int sum = 0;

    sum = array_sum(a, sizeof(a)/sizeof(int));

    printf("sum=%d\n", sum);

    return 0;

}

int array_sum(int * data, int n) { // int * data = a

    int ret = 0;

    for(int i = 0; i < n; i++) {
        ret += *(data+i); // ret += data[i];
    }

    return ret;

}