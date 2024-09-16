#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <string.h>

int main(int argc, char * argv[]) {

    int fd;
    char buf[20];

    if((fd = open("test.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0) {
        perror("open error");
        return -1;
    }

    while(fgets(buf, 20, stdin) != NULL) {
        if(strcmp(buf, "quit\n") == 0) break;
        write(fd, buf, strlen(buf));
    }

    return 0;

}
