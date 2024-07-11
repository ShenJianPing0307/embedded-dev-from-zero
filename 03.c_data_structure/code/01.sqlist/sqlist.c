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

int list_clear(sqlink, L) {

    if(L == NULL) {
        return -1;
    }
    memset(L, 0, sizeof(sqlist));
    L->last = -1;
    return 0;

}

int list_free(sqlink L) {

    if(L == NULL) {
        return -1;
    }
    free(sqlink);
    sqlink == NULL;
    return 0;

}
/*
* Is list empty
*/
int list_empty(sqlink L) {
    if(L->last == -1) {
        return 1;
    }
    return 0;
}

int list_length() {
    if(L == NULL) {
        return -1;
    }
    return (L->last+1);
}

int list_locate(sqlink L, data_t value) {
    int i;
    for(i = 0; i <= L->last; i++) {
        if(L->data[i] == value) {
            return i;
        }
    }
    return -1;
}

int list_insert(sqlink L, data_t value, int pos) {
    int i;

    //full
    if(L->last == N-1) {
        printf("list is full\n");
        return -1;
    }

    //check param pos [0, last+1]
    if(pos < 0 || pos > L->last+1) {
        printf("pos is invalid\n");
        return -1;
    }

    //move
    for(i = L->last; i >= pos; i--) {
        L->data[i+1] = L->data[i];
    }

    //update value last
    L->data[pos] = value;
    L->last++;

    return 0
}