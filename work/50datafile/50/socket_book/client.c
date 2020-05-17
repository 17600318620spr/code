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
	int client_socket;
	struct sockaddr_in serveraddr;
#if 0
	if(argc<3)
	{
		printf("Usage:%s <ip> <port>\n", argv[0]);
		exit(-1);
	}
#endif
	client_socket=socket(AF_INET, SOCK_STREAM, 0);
	if(client_socket==-1)
	{
		perror("socket");
		exit(-1);
	}

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(atoi("6688"));
//	serveraddr.sin_port=htons(atoi(argv[2]));
//	serveraddr.sin_addr.s_addr=inet_addr(argv[1]);
	serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
//	inet_aton(argv[1], &serveraddr.sin_addr);

	if(connect(client_socket, (struct sockaddr *)&serveraddr, sizeof(serveraddr))==-1)
	{
		perror("connect");
		exit(-1);
	}

	char file_name[FILE_NAME_MAX_SIZE+1];
	memset(file_name, 0, sizeof(file_name));
	printf("please input file name on server:\t");
	scanf("%s", file_name);

	char buf[BUFFERSIZE];
	memset(buf, 0, sizeof(buf));
	strncpy(buf, file_name, strlen(file_name) > BUFFERSIZE ? BUFFERSIZE : strlen(file_name));

	send(client_socket, buf, BUFFERSIZE, 0);

	FILE *fp=fopen(file_name, "w");
	if(fp==NULL)
	{
		perror("fopen");
		exit(-1);
	}
#if 0
	char buf[BUFFERSIZE]="Hello server";
	send(client_socket, buf, sizeof(buf), 0);
	if(recv(client_socket, buf, sizeof(buf), 0)==-1)
	{
		perror("recv");
		exit(-1);
	}
	printf("recv from server:%s\n", buf);
#endif
	memset(buf, 0, sizeof(buf));
	int length=0;
	while(length=recv(client_socket, buf, BUFFERSIZE, 0))
	{
		if(length<0)
		{
			printf("receive data from server %s failed\n", argv[1]);
			break;
		}

		int write_length=fwrite(buf, sizeof(char), length, fp);
		if(write_length<length)
		{
			printf("%s write failed\n", file_name);
			break;
		}
		memset(buf, 0, sizeof(buf));
	}
	printf("receive %s from server[%s] finished\n", file_name, argv[1]);
	fclose(fp);
	close(client_socket);
	
	return 0;
}
