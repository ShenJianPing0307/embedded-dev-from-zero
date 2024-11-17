#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *func(void *arg) {
    printf("this is child thread\n");
    sleep(25);
    pthread_exit("thread return");
}

int main() {

    pthread_t tid[1000];
    void *retv;
    int i;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    for(i=0; i<1000; i++) {

        pthread_create(&tid[i], &attr, func, NULL);

    }

    while(1) {

        sleep(1);

    }


}