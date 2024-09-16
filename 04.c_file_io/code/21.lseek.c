#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {

    int fd, ret;
    char buf[32] = "hello world!";
    char buf2[32] = {0};

    if((fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, 0666)) < 0) {
        perror("open\n");
        return -1;
    }

    if((ret = write(fd, buf, strlen(buf))) < 0) {
        perror("write\n");
        goto END;
    }

    lseek(fd, 0, SEEK_SET); //将指针定位到第一个，因为写完数据后指针在末尾

    if((ret = read(fd, buf2, 32)) < 0) {
        perror("read\n");
        goto END;
    }

    buf2[31] = 0; //buf2写满字符串后\0结尾，为了不继续读取成乱码，手动加一个0

    printf("read buf2=%s\n", buf2);


END:
    close(fd);

    return 0;

}