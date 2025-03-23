#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define N 32

#define R 1 // usr - register
#define L 2 // usr - login
#define Q 3 // usr - query
#define H 4 // usr - history

// 定义双方通信信息结构体
typedef struct {
    int type;
    char name[N];
    char data[256];
}MSG;

int do_register(int sockfd, MSG *msg) {
    msg->type = R;
    printf("Input name:");
    scanf("%s", msg->name);
    getchar();

    printf("Input passwd:");
    scanf("%s", msg->data);

    if(send(sockfd, msg, sizeof(MSG), 0) < 0) {
        printf("fail to send.\n");
        return -1;
    }

    if(recv(sockfd, msg, sizeof(MSG), 0) < 0) {
        printf("fail to recv.\n");
        return -1;
    }

    // success or usr already exist.
    printf("%s\n", msg->data);

    return 0;

}

// ./client 192.168.1.244 33201
int main(int argc, const char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    int n;
    MSG msg;

    if(argc != 3) {
        printf("Usage:%s serverip port.\n", argv[0]);
        return -1;
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("fail to socket.\n");
        return -1;
    }

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if(connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("fail to connect");
		return -1;
    }

    while(1) {
        printf("*************************************\n");
        printf("* 1.register     2.login    3.quit  *\n");
        printf("*************************************\n");
        printf("Please choose:");

        scanf("%d", &n);
        getchar();

        switch(n) {
            case 1:
                do_register(sockfd, &msg);
                break;
            default:
                printf("Invalid data cmd.\n");
                break;
        }
    }

    return 0;
}
