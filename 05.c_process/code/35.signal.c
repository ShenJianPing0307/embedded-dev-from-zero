#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


typedef void (*sighandler_t)(int);

sighandler_t oldact;

void handle(int sig) {
    printf("Catch the SIGINT\n");
}

int main() {

    oldact = signal(SIGINT, handle);

    while(1) {
        sleep(1);
    }

}