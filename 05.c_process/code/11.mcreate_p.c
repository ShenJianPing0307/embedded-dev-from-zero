#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *testThread(void *arg){

    printf("this is thread test, pid=%d, tid=%lu\n", getpid(), pthread_self());
    printf("this is %d thread\n", (int)arg);
    while(1) {
        sleep(1);
    }

}

int main() {

    pthread_t tid[5];
    int ret;
    int arg = 5;
    int i;

    for(i=0; i<5;i++) {
        ret = pthread_create(&tid[i], NULL, testThread, (void *)i);
        printf("this is main thread, tid=%lu\n", tid[i]);
    }

    while(1) {

        sleep(1);

    }

}