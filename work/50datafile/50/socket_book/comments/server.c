#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define BUFFERSIZE 128
#define FILE_NAME_MAX_SIZE 512

int main(int argc, const char *argv[])
{
	int server_socket;
	struct sockaddr_in serveraddr;

	if(argc<3)
	{
		printf("Usage:%s <ip> <port>\n", argv[0]);
		exit(-1);
	}

	//用server_socket代表服务器向客户端提供服务的接口
	server_socket=socket(AF_INET, SOCK_STREAM, 0);
	if(server_socket==-1)
	{
		perror("socket");
		exit(-1);
	}
	printf("server_socket=%d\n", server_socket);

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(atoi(argv[2]));
	serveraddr.sin_addr.s_addr=htons(INADDR_ANY);

	//把socket和socket地址结构绑定
	if(bind(server_socket, (struct sockaddr *)&serveraddr, sizeof(serveraddr))==-1)
	{
		perror("bind");
		exit(-1);
	}
	printf("bind success!\n");

	// server_socket用于监听
	if(listen(server_socket, 10)==-1)
	{
		perror("listen");
		exit(-1);
	}
	printf("Listening...\n");

	//服务器端一直运行用以持续为客户端提供服务
	while(1)
	{
		//定义客户端的socket地址结构client_addr，当收到来自客户端的请求后，调用accept接受此请求，
		//同时将client端的地址和端口等信息写入client_addr中
		struct sockaddr_in clientaddr;
		socklen_t len=sizeof(clientaddr);

		//接受一个从client端到达server端的连接请求,将客户端的信息保存在client_addr中
	    //如果没有连接请求，则一直等待直到有连接请求为止，这是accept函数的特性，可以用select()来实现超时检测
	    //accpet返回一个新的socket,这个socket用来与此次连接到server的client进行通信,这里的connectfd代表了这个通信通道
		int connectfd=accept(server_socket, (struct sockaddr *)&clientaddr, &len);
		if(connectfd==-1)
		{
			perror("accept");
			exit(-1);
		}

		char buf[BUFFERSIZE];
		memset(buf, 0, sizeof(buf));
		if(recv(connectfd, buf, BUFFERSIZE, 0)==-1)
		{
//			perror("recv");
			printf("Server receive data failed\n");
			exit(-1);
		}
#if 0
		printf("Received a message:%s\n", buf);
		strcpy(buf, "Welcome to server");
		send(connectfd, buf, BUFFERSIZE, 0);
#endif
		char file_name[FILE_NAME_MAX_SIZE+1];
		memset(file_name, 0, sizeof(file_name));
		strncpy(file_name, buf, strlen(buf) > FILE_NAME_MAX_SIZE ? FILE_NAME_MAX_SIZE : strlen(buf));
		
		FILE *fp=fopen(file_name, "r");
		if(fp==NULL)
		{
//			perror("fopen");
			printf("%s not found\n", file_name);
			exit(-1);
		}
		else
		{
			memset(buf, 0, sizeof(buf));
			int file_length=0;
			while((file_length=fread(buf, sizeof(char), BUFFERSIZE, fp))>0)
			{
				// 发送buf中的字符串到connectfd,实际上就是发送给客户端
				if(send(connectfd, buf, file_length, 0)<0)
				{
					perror("send");
					break;
				}
				memset(buf, 0, sizeof(buf));
			}
			fclose(fp);
			printf("send %s finished\n", file_name);
		}
		close(connectfd);
	}
	close(server_socket);

	return 0;
}
