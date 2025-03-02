#include "net.h"

int main() {

    int fd = -1;
    struct sockaddr_in sin;

    /*1、创建socket fd*/
    if((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    /*2、允许套接字地址快速重用*/
    int b_reuse = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &b_reuse, sizeof(int));

    /*2.1 填充struct socketadd_in结构体*/
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(SERV_PORT);

    /*2.2 让服务器绑定能绑定到任意的IP上*/
#if 1
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
#else
    if(inet_pton(AF_INET, SERV_IP_ADDR, (void *)&sin.sin_addr) != 1) {
        perror("inet_pton");
        return 1;
    }
#endif
    /*2.3 绑定*/
    if(bind(fd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("bind");
        return 1;
    }
    char buf[BUFSIZ];
    struct sockaddr_in cin;
    socklen_t addrlen = sizeof(cin);
    printf("\nUDP server started\n");
    while(1) {
        bzero(buf, BUFSIZ);
        if(recvfrom(fd, buf, BUFSIZ-1, 0, (struct sockaddr *)&cin, &addrlen) < 0) {
            perror("recvfrom");
            continue;
        }

        char ipv4_addr[16];
        if(!inet_ntop(AF_INET, (void *)&cin.sin_addr, ipv4_addr, sizeof(cin))) {
            perror("inet_ntop");
            return 1;
        }

		printf("Recived from(%s:%d), data:%s",ipv4_addr, ntohs(cin.sin_port), buf);

		if (!strncasecmp (buf, QUIT_STR, strlen (QUIT_STR))) {  //用户输入了quit字符
                       printf ("Client(%s:%d) is exiting!\n", ipv4_addr, ntohs(cin.sin_port));
                }

	}

	close(fd);

	return 0;

}