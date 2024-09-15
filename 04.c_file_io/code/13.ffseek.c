#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *fp;

    if((fp=fopen("1.txt", "w")) == NULL) {
        perror("fopen");
        return 0;
    }

    fwrite("abcdef", 6, 1, fp);
    printf("current position fp=%d\n", (int)ftell(fp)); // abcd
    rewind(fp);
    printf("after rewind fp=%d\n", (int)ftell(fp));
    fwrite("jkl", 3, 1, fp); // jklabcd

    return 0;

}
