#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    int fpret;

    if ((fp = fopen("1.txt", "r")) == NULL) {

        perror("fopen");
        printf("errno: %d fopen:%s\n", errno, strerror(errno));
    } else {
        printf("fopen success\n");
        if ((fpret = fclose(fp)) == 0) {
            printf("fclose success\n");
        } else {
            perror("fclose");
        }
    }

    return 0;

}

