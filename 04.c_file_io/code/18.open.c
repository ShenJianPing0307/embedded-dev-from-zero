#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int fd;
    int ret;

    if((fd=open("test.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0) {
        perror("open error");
        return -1;

    }

    printf("success, fd=%d\n", fd);

    if((ret=close(fd)) < 0) {
    perror("close error");
    return -1;
    }

    return 0;

}