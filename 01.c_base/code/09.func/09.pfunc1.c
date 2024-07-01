#include <stdio.h>

char * getStr();

int main(int argc, char *argv[]) {

    char * r;

    r = getStr();

    printf("---%s---\n", getStr());

    puts(r);

    return 0;

}

char * getStr() {

    char * str = "hello";

    return str;

}

