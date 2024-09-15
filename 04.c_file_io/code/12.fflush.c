#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    if((fp = fopen("1.txt", "w")) == NULL) {
        perror("fopen");
        return 0;
    }

    fwrite("abcdef", 7, 1, fp);
    fflush(fp);

    while(1) {
        sleep(1);
    }

    return 0;

}