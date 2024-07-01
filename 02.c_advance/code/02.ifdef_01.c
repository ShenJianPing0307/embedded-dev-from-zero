#include <stdio.h>

#define _DEBUG_

int main(int argc, char *argv[]) {


    #ifdef _DEBUG_
        printf("The macro _DEBUG_ is defined\n");
    #else
        printf("The macro _DEBUG_ is not defined\n");
    #endif

}