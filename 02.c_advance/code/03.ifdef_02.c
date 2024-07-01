#include <stdio.h>

#define _DEBUG_ 1

int main(int argc, char *argv[]) {

    #if _DEBUG_
        printf("The macro _DEBUG_ is defined\n");
    #else
        printf("The macro _DEBUG_ is not defined\n");
    #endif

}