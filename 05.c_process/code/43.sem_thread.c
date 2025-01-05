#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <pthread.h>
#include <signal.h>

sem_t sem_r,sem_w;
char *shmaddr;

void *readmem(void *arg) {
    while(1) {
        sem_wait(&sem_r);
        printf("%s\n", shmaddr);
        sem_post(&sem_w);
    }
}

void destroy_sem(int sig) {
    sem_destroy(&sem_r);
    sem_destroy(&sem_w);
    exit(0);
}

int main() {

    key_t key;
    int shmid;
    key = ftok(".", 100);
    if(key<0) {
        perror("ftok");
        return 0;
    }

    shmid = shmget(key, 500, 0666|IPC_CREAT);
    if(shmid < 0) {
        perror("shmget");
        return 0;
    }

    shmaddr = shmat(shmid, NULL, 0);

    struct sigaction act;
    act.sa_handler = destroy_sem;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGINT, &act, NULL);

    sem_init(&sem_r, 0, 0);
    sem_init(&sem_w, 0, 1);

    pthread_t tid;
    pthread_create(&tid, NULL, readmem, NULL);

    while(1) {
        sem_wait(&sem_w);
        printf(">:");
        fgets(shmaddr, 500, stdin);
        sem_post(&sem_r);
    }

}