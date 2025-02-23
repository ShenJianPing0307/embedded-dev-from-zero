#include <pthread.h>
#include "net.h"

void cli_data_handle(void *arg);

int main() {

    int fd = 1;
    struct sockaddr_in sin;

    /*1、创建socket fd*/
    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

     /* 允许本地的地址和端口快速重用 */
    int b_reuse = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &b_reuse, sizeof(int));

    /*2、绑定*/
    /*2.1 填充struct sockaddr_in结构体变量*/
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(SERV_PORT); //网络字节序的端口号

    /*优化1、让服务器能绑定在任意的IP上*/
#if 1
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
#else
    if(inet_pton(AF_INET, SERV_IP_ADDR, (void *)&sin.sin_addr) != 1) {
       perror("inet_pton");
       return 1;
    }
#endif
    /*2.2 绑定*/
    if(bind(fd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
       perror("bind");
       return 1;
    }

    /*3、调用listen()把主动套接字变成被动套接字*/
    if(listen(fd, BACKLOG) < 0) {
        perror("listen");
        return 1;
    }
    printf("Server starting...ok!\n");

    /*4、阻塞等待客户端连接请求*/
    int newfd = 1;

    pthread_t tid;

    struct sockaddr_in cin;
    socklen_t addrlen = sizeof(cin);

    while(1) {

        struct cli_info *pcinfo = NULL;

        if((newfd = accept(fd, (struct sockaddr *)&cin, &addrlen)) < 0) {
        perror("accept");
        return 1;
    }
    /*填充客户端信息*/
    pcinfo = (struct cli_info *)malloc(sizeof(struct cli_info));

    bzero(pcinfo, sizeof(struct cli_info));

    // 填充内核链表
    pcinfo->cli_fd = newfd;
    memcpy(&pcinfo->cin, &cin, sizeof(cin));

    //把cinfo加入到user_info内核链表
    pthread_create(&tid, NULL, (void *)cli_data_handle, (void *)pcinfo);
    pthread_detach(tid);
    }

    close(fd);
    return 0;

}

void cli_data_handle(void *arg) {
    /*5、读写 和newfd进行数据读写*/
    struct cli_info *pcinfo = (struct cli_info *)arg;
    int ret = -1;
    char buf[BUFSIZ];
    char ipaddr[16];

    	/*设置线程的分离属性*/
//	pthread_detach(pthread_self());

	int newfd = pcinfo->cli_fd;
	struct sockaddr_in cin;

	memcpy(&cin ,&pcinfo->cin, sizeof(cin));

    bzero(ipaddr, 16);
    if(!inet_ntop(AF_INET, (void *)&cin.sin_addr, ipaddr, sizeof(cin))) {
            perror("inet_ntop");
            exit(1);
    }
    printf("Client(%s:%d) is conneted!\n", ipaddr,ntohs(cin.sin_port));

	/*5.和客户端进行信息的交互(读写) */
    while(1) {
        bzero(buf, BUFSIZ);
        do {
            ret = read(newfd, buf, BUFSIZ-1);
        } while(ret < 0 && EINTR == errno);
        if(ret < 0){
            perror("read");
            exit(0);
        }
        if(!ret) { // 对方已经关闭
            break;
        }
        printf("Receive data: %s\n", buf);

        if(!strncasecmp(buf, QUIT_STR, strlen(QUIT_STR))) { //用户输入了quit字符
            printf("Client is existing!\n");
            break;
        }
    }
    close(newfd);
}