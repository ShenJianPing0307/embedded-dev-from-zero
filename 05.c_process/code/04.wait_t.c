#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

    int status;
    pid_t pid;
    pid_t rpid;
    pid = fork();

    if(pid < 0) {
        perror("fork");
        exit(1);
    } else if(pid == 0) {
        sleep(10);
        printf("child will exit\n");
        exit(0);
    } else if(pid > 0) {
//        wait(&status);
        waitpid(-1,&status,WNOHANG);
        sleep(20);
        printf("Get child status=%x\n", WEXITSTATUS(status));
    }

    while(1) {
        sleep(1);
    }


}