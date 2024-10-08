#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    FILE *fp;
    char *buff;
    size_t ret;

    if((fp=fopen("1.txt", "r")) == NULL) {
        perror("fopen");
        return 0;
    }

    if((buff = (char*)malloc(100)) == NULL) {
        perror("malloc failed");
        return 0;
    }

    ret = fread(buff, 10, 1, fp);
    if(ret == -1) {
        perror("fread");
        goto end;
    }
    printf("buff=%s\n", buff);

end:
    free(buff);
    fclose(fp);

}