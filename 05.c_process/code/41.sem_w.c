#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main() {

    sem_t *sem_r,*sem_w;
    key_t key;
    int shmid;
    char *shmaddr;
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

    sem_r = sem_open("mysem_r", O_CREAT|O_RDWR, 0666, 0);
    sem_w = sem_open("mysem_w", O_CREAT|O_RDWR, 0666, 1);

    while(1) {
        sem_wait(sem_w);
        printf(">:");
        fgets(shmaddr, 500, stdin);
        sem_post(sem_r);
    }

}