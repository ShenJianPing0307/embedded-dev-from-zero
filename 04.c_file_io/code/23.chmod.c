#include "stdio.h"
#include "sys/stat.h"

int main(int argc, char *argv[]) {

    int ret;
    if((ret = chmod("chmod_test.txt", 0666)) < 0) {
        perror("chmod");
        return -1;
    }

    return 0;

}