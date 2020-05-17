#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOCKETS_BUFFER_SIZE  1024
#define SOCKETS_TIMEOUT      2
#define FILE_MAX_LEN 64

#if 0
struct scpi_instrument {
	/* selection */
	bool         serial;
	bool         network;
	char        *id_regex;
	char        *model;
	char        *response;

	/* network based instrument */
	char        *ip_address;
	int    		 main_port;
	int          main_socket;
	int 	     control_port;
	int          control_socket;

	/* serial based instrument */
	char         *tty_path;
	int          ttyfd;
	int          gpib_addr;
};
/* Turn NOdelay on */
static void network_setnodelay(int MySocket)
{
	int StateNODELAY = 1;
	int ret;

	ret = setsockopt(MySocket, IPPROTO_TCP, TCP_NODELAY, (void *)&StateNODELAY, sizeof StateNODELAY);

	if (ret == -1) {
		printf("Error: Unable to set NODELAY option (%i)...\n", errno);
		perror("sockets");
		exit(1);
	}
	return;
}
#endif
void *network_connect(void *arg)
{
//printf(__func__);
//printf("123456789\n");
puts("@@@@@@@@@@@@@@@@@@@@@@");
//	struct scpi_instrument *scpi;
	int socketfd, port;
	char *ip_address;
//	char *ar=(char *)arg;
	struct sockaddr_in MyAddress, MyControlAddress;
	int status;
//	char buf[128];

puts(">>>>>>>>>>>>>>>>>>>>>>");
	/* Create socket (allocate resources) - IPv4, TCP */
	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	if (socketfd == -1) {
		printf("Error: Unable to create socket (%i)...\n", errno);
	}

puts("socketfd 11111111111");
#if 0
	/* set Receive and Transmit Timeout, so connect doesn't take so long to fail */
	status = setsockopt(scpi->main_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
	if (status < 0)
		perror("setsockopt failed\n");

	status = setsockopt(scpi->main_socket, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout,sizeof(timeout));
	if (status < 0)
		perror("setsockopt failed\n");
#endif
	/* Establish TCP connection */
	port=8888;
	ip_address="192.168.0.120";
	memset(&MyAddress, 0, sizeof(struct sockaddr_in));
	MyAddress.sin_family = AF_INET;
	MyAddress.sin_port = htons(port);
	MyAddress.sin_addr.s_addr = inet_addr(ip_address);

printf("port=%d\n", port);
printf("ip_address=%s\n", ip_address);
	status = connect(socketfd, (struct sockaddr *)&MyAddress, sizeof(struct sockaddr_in));
	if(status == -1) {
		printf("Error: Unable to establish connection to ip:%s (%i)...\n", ip_address, errno);
//		printf("Error: Unable to establish connection to ip:%s (%i)...\n", ar, errno);
	}

	/* Minimize latency by setting TCP_NODELAY option */
//	network_setnodelay(scpi->main_socket);

	int total, len;
	char filename[FILE_MAX_LEN+1], buf[1024];
	FILE *fp;

	/* 接收文件名 */
	total = 0;
	while (total < FILE_MAX_LEN)
	{
		len = recv(socketfd, filename+total, (FILE_MAX_LEN-total), 0);
		if(len == -1)
		{
			printf("recv filename fail\n");
			break;
		}
		total += len;
	}

	/* 接收文件名出错 */
	if(total != FILE_MAX_LEN)
	{
		perror("failure file name");
	}
	printf("recv file %s ...\n", filename);

	fp = fopen(filename, "w");
	if(NULL == fp)
	{
		perror("open");
	}

	/* 接收文件数据 */
	printf("\nRecv File Begin!\n");
	total = 0;
	while(1)
	{
		len = recv(socketfd, buf, sizeof(buf), 0);
#if 0
		if(-1 == len)
		{
			printf("recv file data fail\n");
			break;
		}
#endif
		if(!len)
		{
			printf("recv data finished\n");
			break;
		}
		total += len;
		printf("total=%d len=%d\n", total, len);
		printf("buf=%s\n", buf);
		//写入本地文件
		fwrite(buf, 1, len, fp);
		puts("sprsprsprsprspr");
	}

	fclose(fp);
	printf("Recv file %s success! Total length:%d  \n", filename, total);
}


/* simple configuration and streaming */
int main(int argc, char **argv)
{
//	pthread_t tid[2];
	pthread_t tid;
//	char buf[7500];
//	FILE *fpr, *fpw;
//	void *p=malloc(7500);
puts("11111111111111111");
#if 0
	fpr=fopen("data1.txt", "rb");
	fpw=fopen("dt1.txt", "wb");
	fread(buf, 1, sizeof(buf), fpr);
	fwrite(buf, 1, sizeof(buf), fpw);
#endif
//	pthread_create(&tid, NULL, (void *)network_connect, (void *)buf);
printf(__func__);
	int ret=pthread_create(&tid, NULL, network_connect, NULL);
//	int ret=pthread_create(&tid, NULL, network_connect, (void *)argv[1]);
	printf("ret=%d\n", ret);
puts("2222222222");

	ret=pthread_join(tid, NULL);
	if(!ret)
		printf("Thread joined\n");
	else
		printf("Thread join failed\n");
//	fclose(fpr);
//	fclose(fpw);

	return 0;
} 

