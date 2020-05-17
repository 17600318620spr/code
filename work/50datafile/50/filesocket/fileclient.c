/* TCP 文件接收客户端 */
//#include "Head.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <errno.h>
#include <sys/fcntl.h>
#include <sys/wait.h>

#define FILE_MAX_LEN 64
//#define DEFAULT_SVR_PORT 2828
#define DEFAULT_SVR_PORT 6006
 
int main(int argc,char *argv[])
{
	int sockfd, ret, total, len;
	char ip_addr[64];
	unsigned short port;
	struct hostent *he;
	struct sockaddr_in	their_addr;
	char filename[FILE_MAX_LEN+1], buf[1024];
	FILE *fp;
#if 0 
	if(argc < 2)
	{
		printf("Needs server ip!\n");
		exit(1);
	}
#endif
	strncpy(ip_addr, argv[1], sizeof(ip_addr));
//	strncpy(ip_addr, "192.168.0.109", sizeof(ip_addr));
	port = DEFAULT_SVR_PORT;
	if(argc >= 3)
	{
		port = (unsigned short)atoi(argv[2]);
	}
 
	/* 域名解析 */
	// he = gethostbyname(argv[1]);
	/* 第一步: 建立一个TCP套接字 */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd)
	{
		perror("sockfd");
		exit(2);
	}
 
	/* 第二步:设置服务器地址和端口2828 */
	memset(&their_addr,0,sizeof(their_addr));
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(port);
	their_addr.sin_addr.s_addr = inet_addr(ip_addr);
 
	printf("Conect Server %s :%d \n", ip_addr, port);
	/* 第三步: 用connect 和服务器建立连接,使用协议栈自动分配端口 */
	ret = connect(sockfd, (struct sockaddr*)&their_addr, sizeof(struct sockaddr));
	if(-1 == ret)
	{
		perror("connect");
		exit(3);
	}

#if 1
	ret = send(sockfd, "Hello", 6, 0);
	if(ret < 0)
	{
		perror("send");
		exit(4);
	}
#endif
 
	/* 接收文件名 */
	total = 0;
	while(total < FILE_MAX_LEN)
	{
		//接收的buf长度,始终是未接收的文件名长度剩下的长度 
		len = recv(sockfd, filename+total, (FILE_MAX_LEN - total), 0);
		if(len <= 0)
		{
			perror("recv_name");
			break;
		}
 
		total += len;
	}
 
	/* 接收文件名出错 */
	if(total != FILE_MAX_LEN)
	{
		perror("failure file name");
		exit(5);
	}
 
	printf("recv file %s ...\n", filename);

	fp = fopen(filename, "wb");
//	fp = fopen(filename, "ab");
	if(NULL == fp)
	{
		perror("open");
		exit(6);
	}
 
	/* 接收文件数据 */
	printf("\nRecv File Begin!\n");
	total = 0;
	while(1)
	{
		len = recv(sockfd, buf, sizeof(buf), 0);
		if(-1 == len)
		{
			perror("recv_file");
			break;
		}
 
		total += len;
 printf("------------len=%d total=%d \n", len, total);
		//写入本地文件
		fwrite(buf, 1, len, fp);
	}
 
	fclose(fp);
	printf("Recv file %s success! Total length:%d\n", filename, total);
 
	/* 关闭socket */
	close(sockfd);
	return 0;
}
