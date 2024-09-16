#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {

    DIR* dp;
    struct dirent *dt;

    if((dp = opendir("/home/linux/embedded-dev-from-zero/04.c_file_io/code/")) < 0) {
        perror("opendir");
        return -1;

    }

    while((dt = readdir(dp)) != NULL) {
        printf("%s\n", dt->d_name);
    }

    closedir(dp);

}