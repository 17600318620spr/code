//串口相关的头文件
#include<stdio.h>      /*标准输入输出定义*/
#include<stdlib.h>     /*标准函数库定义*/
#include<unistd.h>     /*Unix 标准函数定义*/
#include<sys/types.h> 
#include<sys/stat.h>   
#include<fcntl.h>      /*文件控制定义*/
#include<termios.h>    /*PPSIX 终端控制定义*/
#include<errno.h>      /*错误号定义*/
#include<string.h>

//1.找到串口的设备号  在linux系统下，所有的设备都是文件，所以要先找到串口这个设备文件，之后就可以对这个串口进行操作。
#define UART_DEV "/dev/ttyUSB0" // /dev/tty**串口号
//2.打开串口并初始化串口  串口的打开只需要一个open函数就可以打开，下面有一个初始化的函数，先将串口打开，如果打开成功，会返回一个设备描述符
int uart_init(void)
{
	int fd=0;
	fd=open(UART_DEV, O_RDWR|O_NOCTTY|O_NDELAY, 0666);
	if(fd<0)
	{
		printf("open error!\n");
		return -1;
	}

	set_opt(fd);
	return fd;
}

//set_opt函数用于设置串口的相关基本参数，一般串口都会设置波特率什么的，其余的参数可以用到的时候再查询是什么意思，set_opt函数的定义如下：
int set_opt(int fd)
{
	struct termios old_cfg, new_cfg;
	tcgetattr(fd, &new_cfg);

	new_cfg.c_cflag|=(CLOCAL|CREAD);

	cfsetispeed(&new_cfg, B9600);
	cfsetospeed(&new_cfg, B9600);

	new_cfg.c_cflag &= ~CSIZE;
	new_cfg.c_cflag |= CS8;
	new_cfg.c_cflag &= ~PARENB;
	new_cfg.c_cflag &= ~CSTOPB;
	new_cfg.c_cc[VTIME] = 0;
	new_cfg.c_cc[VMIN] = 0;
	
	tcflush(fd, TCIFLUSH);
	tcsetattr(fd, TCSANOW, &new_cfg);

	return 0;
}

//3.用串口发送一串数据  利用串口发送一串数据，write
int uart_send(int fd, char *str)
{
	int wr_num;
	char buf[1024];

	sprintf(buf, "%s", str);
	wr_num=write(fd, buf, strlen(buf));
	close(fd);
	return wr_num;
}

//4.读出串口接收到的数据, read
int uart_recv(int fd)
{
	int nread;
	char buf[1024];

//	nread=read(fd, buf, LEN);
	nread=read(fd, buf, 1024);
	if(nread>0)
	{
		printf("%s\n", buf);
	}

	close(fd);
	return nread;
}

int main(int argc, const char *argv[])
{
	int fd, ret_send, recv_send;
#if 0
	fd=open("/dev/tty", O_RDWR|O_NOCTTY|O_NDELAY, 0666);
	if(fd<0)
	{
		printf("open fd fail\n");
		return -1;
	}
#endif
	fd=uart_init();

	ret_send=uart_send(fd, "hello");
	recv_send=uart_recv(fd);
	printf("ret_send=%d recv_send=%d\n", ret_send, recv_send);

	return 0;
}
