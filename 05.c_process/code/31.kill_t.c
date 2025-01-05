#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    //kill(2153, 11);
    raise(11);
    alarm(3);
    pause();
}