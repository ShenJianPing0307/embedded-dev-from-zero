#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void *func() {

    pthread_detach(pthread_self());
    printf("this is child thread\n");
    sleep(25);
    pthread_exit("thread return!");

}

int main() {

    pthread_t tid[100];
    void *retv;
    int i;

    for(i=0; i<100; i++) {

        pthread_create(&tid[i], NULL, func, NULL);

    }
    while(1) {
        sleep(1);
    }

}