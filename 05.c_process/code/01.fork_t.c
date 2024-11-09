#include <stdio.h>
#include <unistd.h>

int main() {

    pid_t pid;
    printf("before fork\n");
    pid = fork();
    if(pid > 0) {
        printf("This is father process\n");
        printf("pid=%d\n", getpid());
        printf("father after fork");
        while(1) {
            sleep(1);
            printf("father sleep\n");
        }
    }else if(pid == 0) {
            printf("this is child process\n");
            printf("pid=%d\n", getpid());
            while(1) {

                sleep(1);
                printf("child sleep");

            }
        } else if(pid<0){
            perror("fork");
            return 0;
        }

}