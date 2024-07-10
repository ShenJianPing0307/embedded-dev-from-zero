#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlist.h"

sqlink list_creat() {
    // malloc
    sqlink L;
    L = (sqlink)malloc(sizeof(sqlist));

    if(L == NULL) {
        printf("list malloc failed\n");
        return L;
    }

    //initialize
    memset(L, 0, sizeof(sqlist));
    L->last = -1;

    //return
    return L;

}