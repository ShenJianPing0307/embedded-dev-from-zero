
/*./client serv_ip serv_port */
#include "net.h"

void usage (char *s)
{
	printf ("\n%s serv_ip serv_port", s);
	printf ("\n\t serv_ip: server ip address");
	printf ("\n\t serv_port: server port(>5000)\n\n");
}

int main (int argc, char **argv)
{
	int fd = -1;

	int port = -1;
	struct sockaddr_in sin;

	if (argc != 3) {
		usage (argv[0]);
		exit (1);
	}
	/* 1. 创建socket fd */
	if ((fd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
		perror ("socket");
		exit (1);
	}

	port = atoi (argv[2]);
	if (port < 5000) {
		usage (argv[0]);
		exit (1);
	}
	/*2.连接服务器 */

	/*2.1 填充struct sockaddr_in结构体变量 */
	bzero (&sin, sizeof (sin));

	sin.sin_family = AF_INET;
	sin.sin_port = htons (port);	//网络字节序的端口号
#if 0
	sin.sin_addr.s_addr = inet_addr (SERV_IP_ADDR);
#else
	if (inet_pton (AF_INET, argv[1], (void *) &sin.sin_addr) != 1) {
		perror ("inet_pton");
		exit (1);
	}
#endif

	if (connect (fd, (struct sockaddr *) &sin, sizeof (sin)) < 0) {
		perror ("connect");
		exit (1);
	}

	printf ("Client staring...OK!\n");

	int ret = -1;
	fd_set rset;
	int maxfd = -1;
	struct timeval tout;
	char buf[BUFSIZ];

	while (1) {
		FD_ZERO (&rset);
		FD_SET (0, &rset);
		FD_SET (fd, &rset);
		maxfd = fd;

		tout.tv_sec = 5;
		tout.tv_usec = 0;

		select (maxfd + 1, &rset, NULL, NULL, &tout);
		if (FD_ISSET (0, &rset)) {	//标准键盘上有输入
			//读取键盘输入，发送到网络套接字fd
			bzero (buf, BUFSIZ);
			do {
				ret = read (0, buf, BUFSIZ - 1);
			} while (ret < 0 && EINTR == errno);
			if (ret < 0) {
				perror ("read");
				continue;
			}
			if (!ret)
				continue;

			if (write (fd, buf, strlen (buf)) < 0) {
				perror ("write() to socket");
				continue;
			}

			if (!strncasecmp (buf, QUIT_STR, strlen (QUIT_STR))) {	//用户输入了quit字符
				printf ("Client is exiting!\n");
				break;
			}
		}

		if (FD_ISSET (fd, &rset)) {	//服务器给发送过来了数据
			//读取套接字数据，处理
			bzero (buf, BUFSIZ);
			do {
				ret = read (fd, buf, BUFSIZ - 1);
			} while (ret < 0 && EINTR == errno);
			if (ret < 0) {
				perror ("read from socket");
				continue;
			}
			if (!ret)
				break;			/* 服务器关闭 */

			//There is a BUG,FIXME!!
			printf ("server said: %s\n", buf);
			if ((strlen(buf) > strlen(SERV_RESP_STR))
				&& !strncasecmp (buf+strlen(SERV_RESP_STR), QUIT_STR, strlen (QUIT_STR))) {	//用户输入了quit字符
				printf ("Sender Client is exiting!\n");
				break;
			}

		}
	}

	/*4.关闭套接字 */
	close (fd);
}
