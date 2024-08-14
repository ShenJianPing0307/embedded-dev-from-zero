#include <stdio.h>
#include "sequeue.h"

int main(int argv, const char *argc[]) {

    sequeue *sq;

    if ((sq = queue_create()) == NULL) {
        return -1;
    }

    enqueue(sq, 10);
    enqueue(sq, 100);
    enqueue(sq, 1000);

    while (!queue_empty(sq)) {
        printf("dequeue:%d\n", dequeue(sq));
    }

    queue_free(sq);

    return 0;
}