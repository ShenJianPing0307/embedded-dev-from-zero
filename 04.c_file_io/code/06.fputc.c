#include <stdio.h>

int main(int argc,  char * argv[]) {

    FILE *fp;
    int ch;

    if ((fp = fopen("1.txt", "w")) == NULL) {

        perror("fopen");
        return -1;

    }

    for (ch = 'a'; ch <= 'z'; ch++) {

        fputc(ch, fp);

    }

    return 0;

}