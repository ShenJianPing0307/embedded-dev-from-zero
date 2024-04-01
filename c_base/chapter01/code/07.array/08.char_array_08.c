#include <stdio.h>

int main(int argc, char *argv[]) {

    char arr1[] = {'a', 'b', 'c'};
    char arr2[] = {'d', 'e', 'f'};
    char arr3[] = {'a', 'b', 'c', '\0'};
    char arr4[] = {'d', 'e', 'f', '\0'};

    printf("arr1:%s %p\n", arr1, &arr1[2]);
    printf("arr2:%s %p\n", arr2, arr2);

    printf("arr3:%s %p\n", arr3, &arr3[2]);
    printf("arr4:%s %p\n", arr4, arr4);

    return 0;
}
/*
arr1:abcdefabc 0xbfff6730
arr2:defabc 0xbfff6731

arr3:abc 0xbfff6736
arr4:def 0xbfff6738
*/