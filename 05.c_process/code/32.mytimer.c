#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handle(int sig) {
    if(sig == SIGINT) {
        printf("Catch the SIGINT\n");
    }else if(sig == SIGALRM) {
        printf("Catch the SIGALRM\n");
    }
}

int main() {

    struct sigaction act;
    act.sa_handler = handle;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);

    struct itimerval timevalue;
    timevalue.it_interval.tv_sec = 1;
    timevalue.it_interval.tv_usec = 0;
    timevalue.it_value.tv_sec = 5;
    timevalue.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &timevalue, NULL);
    sigaction(SIGALRM, &act, NULL);

    while(1) {
        sleep(1);
    }
}