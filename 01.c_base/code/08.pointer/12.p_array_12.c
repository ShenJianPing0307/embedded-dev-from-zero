#include <stdio.h>

int main(int argc, char *argv[]) {

    int a[] = {3, 6, 9};
    int * p[2] = {&a[0], &a[1]}; // int * -- p[0] p[1]

    printf("p[0]--%p p[1]--%p\n", p[0], p[1]); // p[0]--0xbf865970 p[1]--0xbf865974
    printf("&a[0]--%p &a[1]--%p\n", &a[0], &a[1]); // &a[0]--0xbf865970 &a[1]--0xbf865974

    return 0;

}