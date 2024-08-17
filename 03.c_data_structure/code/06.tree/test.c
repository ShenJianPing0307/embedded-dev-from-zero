#include <stdio.h>
#include "tree.h"

int main(int argc, const char *argv[]) {

    bitree * r;

    if ((r = tree_create()) == NULL) {
        return -1;
    }

    preorder(r);
    puts("");

    inorder(r);
    puts("");

    postorder(r);
    puts("");

    layerorder(r);

    return 0;

}