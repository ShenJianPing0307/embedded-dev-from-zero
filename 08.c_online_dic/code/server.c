#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sqlite3.h>
#include <signal.h>
#include <time.h>

#define N 32

#define R 1 //user - register
#define L 2 //user - login
#define Q 3 //user - query
#define H 4 //user - history

#define DATABASE "my.db"


//定义通信双方信息结构体
typedef struct {
    int type;
    char name[N];
    char data[256];
}MSG;

// ./server 192.168.1.244 33201
int main(int argc, const char *argv[]) {

    int sockfd;
    struct sockaddr_in serveraddr;
    int n;
    MSG msg;
    sqlite3 *db;
    int acceptfd;
    pid_t pid;

    if(argc != 3) {
        printf("Usage:%s serverip port.\n", argv[0]);
        return -1;
    }

    //打开数据库
    if(sqlite3_open(DATABASE, &db) != SQLITE_OK) {
        printf("%s\n", sqlite3_errmsg(db));
        return -1;
    } else {
        printf("open DATABASE success.\n");
    }


}




