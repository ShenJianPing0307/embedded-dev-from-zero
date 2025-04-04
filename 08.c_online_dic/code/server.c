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
int do_login(int acceptfd, MSG *msg, sqlite3 *db);
int do_query(int acceptfd, MSG *msg, sqlite3 *db);
int do_history(int acceptfd, MSG *msg, sqlite3 *db);
int history_callback(void* arg,int f_num,char** f_value,char** f_name);
int do_search(int acceptfd, MSG *msg, char word[]);
int get_date(char *date);

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
            case L:
                do_login(acceptfd, &msg, db);
                break;
            case Q:
                do_query(acceptfd, &msg, db);
                break;
            case H:
                do_history(acceptfd, &msg, db);
                break;
            default:
                printf("Invalid data msg.\n");
        }
    }
    printf("client exit.\n");
    close(acceptfd);
    return 0;
}

int history_callback(void* arg, int f_num, char** f_value, char** f_name) {
    // record name date word
    int acceptfd;
    MSG msg;

    acceptfd = *((int *)arg);
    sprintf(msg.data, "%s, %s", f_value[1], f_value[2]);

    send(acceptfd, &msg, sizeof(MSG), 0);

    return 0;
}

int do_history(int acceptfd, MSG *msg, sqlite3 *db) {
    char sql[128] = {};
    char *errmsg;

    sprintf(sql, "select * from record where name = '%s'", msg->name);

    //查询数据库
    if(sqlite3_exec(db, sql, history_callback, (void *)&acceptfd, &errmsg) != SQLITE_OK) {
        printf("%s\n", errmsg);
    } else {
        printf("Query record done.\n");
    }

    //所有的记录查询发送完毕之后 给客户端发送结束消息
    msg->data[0] = '\0';
    send(acceptfd, msg, sizeof(MSG), 0);

    return 0;
}

int do_search(int acceptfd, MSG *msg, char word[]) {

    FILE * fp;
    int len = 0;
    char temp[512] = {};
    int result;
    char *p;

    //打开文件 读取文件 进行对比
    if((fp = fopen("dict.txt", "r")) == NULL) {
        perror("fail to open.\n");
        strcpy(msg->data, "Failed to open dict.txt");
        send(acceptfd, msg, sizeof(MSG), 0);
        return -1;
    }

    //打印出客户端要查询的单词
    len = strlen(word);
    printf("%s, len=%d\n", word, len);

    //读文件 查询单词
    while(fgets(temp, 512, fp) != NULL) {
        printf("temp=%s\n", temp)
        result = strncmp(temp, word, len);

        if(result < 0) {
            continue;
        }

        if(result > 0 || ((result == 0) && (temp[len] != ' '))) {
            break;
        }

        // 表示找到了要查询的单词
        p = temp + len;
        printf("found word: %s\n", p);
        while(*p == ' ') {
            p++;
        }

        // 找到了注释 跳过所有的空格
        strcpy(msg->data, p);
        printf("found word:%s\n", msg->data);

        // 注释拷贝完毕后 关闭所有文件
        fclose(fp);

        return 1;

    }
    fclose(fp);
    return 0;

}

int get_date(char *date) {

    time_t t;
    struct tm *tp;

    time(&t);

    // 进行时间格式转换
    tp = localtime(&t);

    sprintf(date, "%d-%d-%d %d:%d:%d", tp->tm_year + 1900, tp->tm_mon+1, tp->tm_mday,
                tp->tm_hour, tp->tm_min, tp->tm_sec);

    printf("get date: %s\n", date);

    return 0;

}

int do_query(int acceptfd, MSG *msg, sqlite3 *db) {

    char word[64];
    int found = 0;
    char date[128] = {};
    char sql[128] = {};
    char *errmsg;

    //拿出msg结构体中要查询的单词
    strcpy(word, msg->data);

    found = do_search(acceptfd, msg, word);
    printf("查询单词完毕.\n");

    if(found == 1) {
        // 需要获取系统时间
        get_date(date);
        sprintf(sql, "insert into record values('%s', '%s', '%s')", msg->name, date, word);

        if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK) {

            printf("%s\n", errmsg);
            return -1;

        } else {
            printf("Insert record done.\n");
        }
    } else {
        // 表示未找到
        strcpy(msg->data, "Not Found!");
    }
        // 将查询的结果 发送给客户端
        send(acceptfd, msg, sizeof(MSG), 0);

    return 0;
}

int do_login(int acceptfd, MSG *msg, sqlite3 *db){

    char sql[128] = {};
    char *errmsg;
    int nrow;
    int ncoloumn;
    char **resultp;

    sprintf(sql, "select * from usr where name='%s' and paas='%s';", msg->name, msg->data);
    printf("%s\n", sql);

    if(sqlite3_get_table(db, sql, &resultp, &nrow, &ncoloumn, &errmsg) != SQLITE_OK) {
        printf("%s\n", errmsg);
        return -1;

    } else {
        printf("get table ok\n");
    }
    // 查询成功，数据库中拥有此用户
    if(nrow == 1) {
        strcpy(msg->data, "ok");
        send(acceptfd, msg, sizeof(MSG), 0);
        return 1;
    }

    // 密码或用户名错误
    if(nrow == 0) {
        strcpy(msg->data, "usr/pass wrong.");
        send(acceptfd, msg, sizeof(MSG), 0);
    }

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

