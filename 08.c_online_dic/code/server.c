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

int do_client(int acceptfd, sqlite3 *db);
int do_register(int acceptfd, MSG *msg, sqlite3 *db);

// ./server 192.168.1.244 33201
int main(int argc, const char *argv[]) {

    int sockfd;
    struct sockaddr_in serveraddr;
    int n;
    MSG msg;
    sqlite3 *db;
    char *errmsg;
    int acceptfd;
    pid_t pid;

    if(argc != 3) {
        printf("Usage:%s serverip port.\n", argv[0]);
        return -1;
    }

    //创建数据库
    if(sqlite3_open(DATABASE, &db) != SQLITE_OK) {
        printf("%s\n", sqlite3_errmsg(db));
        return -1;
    } else {
       printf("Create or open success.\n");
    }
    //创建数据库表
#if 0
    if(sqlite3_exec(db, "create table usr(name text primary key, paas text);create table record(name text, date text, word text);", \
    NULL, NULL, &errmsg) != SQLITE_OK) {
       printf("%s\n", errmsg);
       return -1;
    }
#endif

    //创建socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("fail to sokcet.\n");
        return -1;
    }

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if(bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("fail to bind.\n");
        return -1;
    }

    // 将套接字设为监听模式
    if(listen(sockfd, 5) < 0) {
        perror("fail to listen.\n");
        return -1;
    }

    // 处理僵尸进程
    signal(SIGCHLD, SIG_IGN);
    // 接受客户端请求，创建子进程处理
    while(1) {
        if((acceptfd = accept(sockfd, NULL, NULL)) < 0) {
            perror("fail to accept.\n");
            return -1;
        }

        if((pid = fork()) < 0) {
            perror("fail to fork.\n");
            return -1;
        } else if(pid == 0) { // 子进程 处理客户端请求
            close(sockfd);
            do_client(acceptfd, db);
            return 0;
        } else { //父进程 用来接收客户端请求
            close(acceptfd);
        }
    }
    return 0;
}

int do_client(int acceptfd, sqlite3 *db) {

    MSG msg;

    while(recv(acceptfd, &msg, sizeof(msg), 0) > 0) {

        printf("type:%d\n", msg.type);
        switch(msg.type) {
            case R:
                do_register(acceptfd, &msg, db);
                break;
            default:
                printf("Invalid data msg.\n");
        }
    }
    printf("client exit.\n");
    close(acceptfd);

    return 0;
}

int do_register(int acceptfd, MSG *msg, sqlite3 *db) {

    char * errmsg;
    char sql[128];

    sprintf(sql, "insert into usr values('%s','%s')", msg->name, msg->data);
    printf("%s\n", sql);

    if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        printf("%s\n", errmsg);
        strcpy(msg->data, "usr name already exit.");
    } else {
        printf("client register success.\n");
        strcpy(msg->data, "client register success!");
    }

    if(send(acceptfd, msg, sizeof(MSG), 0) < 0) {
        perror("fail to send.\n");
        return -1;
    }
    return 0;
}

