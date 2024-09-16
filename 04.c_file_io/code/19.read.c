#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int fd, n, total = 0;
    char buf[64];

    if((fd = open("test.txt", O_RDONLY)) < 0) {
        perror("open");
        return -1;
    }

    while((n = read(fd, buf, 64)) > 0) {
        total += n;
    }

    printf("buf:%s\n", buf);

    return 0;

}