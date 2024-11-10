#include <stdio.h>
#include <unistd.h>

int main(void) {

    printf("before exec\n");
    if(execlp("/bin/ls", "ls", "-a", "-l", "./", NULL) < 0) {
        perror("execlp");
    }

}