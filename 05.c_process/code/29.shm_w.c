#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    key_t key;
    int shmid;
    char *buf;

    key = ftok("keytest", 100); // keytest文件
    if(key<0){
        perror("ftok");
        return 0;
    }
    printf("key=%x\n", key);

    shmid = shmget(key, 512, IPC_CREAT|0666);
    if(shmid<0) {
        perror("shmget");
        return 0;
    }

    printf("shmid=%d\n", shmid);

    buf = shmat(shmid, NULL, 0);
    if(buf<0) {
        perror("shmat");
        return 0;
    }

    strcpy(buf, "hello world!");

}