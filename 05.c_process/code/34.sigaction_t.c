#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void handle(int sig){
   if(sig == SIGINT){
        printf("I cath the SIGINT \n");
   }else if (sig==SIGALRM){
       printf("second timer \n");
       alarm(1);
   }
}

int main() {

    struct sigaction act;
    act.sa_handler = handle;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGINT, &act, NULL);
    alarm(1);
    sigaction(SIGALRM, &act, NULL);

    while(1) {
        sleep(1);
    }

}