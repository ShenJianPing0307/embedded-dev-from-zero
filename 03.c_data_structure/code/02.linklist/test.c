#include <stdio.h>
#include "linklist.h"

int main(int argc, const char *argv[]) {

    linklist H;
    int value;

    H = list_create();
    if (H == NULL) {
        return -1;
    }

    printf("input:");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        list_tail_insert(H, value);
        printf("input:");
    }

    list_show(H);
    list_insert(H, 100, 0);
    list_show(H);

    return 0;

}