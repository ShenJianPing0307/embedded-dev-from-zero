#include <stdio.h>

int main(int argc, char *argv[]) {
    char arr[] = {"abc"};
    char arr2[] = {'a', 'b', 'c', '\0'};

    printf("%d %d\n", sizeof(arr), sizeof(arr2)); // 4 4
    printf("%s %s\n", arr, arr2); //abc abc

    return 0;
}