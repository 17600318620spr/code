/*************************************************************************
	#	 FileName	: pthreadsem.c
	#	 Author		: fengjunhui 
	#	 Email		: 18883765905@163.com 
	#	 Created	: 2017年12月22日 星期五 14时18分56秒
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define N 64
typedef struct message{
	char buf[N];
	int len;
}msg_t;

sem_t sem_reverse;
sem_t sem_printf;

void* reverse_msgbuf(void* arg)
{
	msg_t *msg = (msg_t *)arg;
	int i = 0;
	char tmp;
	while(1)
	{
		sem_wait(&sem_reverse);
		printf("reverse_msgbuf -------------\n");

		for(i = 0; i < msg->len/2; i++)
		{
			tmp 					  = msg->buf[i];
			msg->buf[i] 			  = msg->buf[msg->len - i - 1];
			msg->buf[msg->len - i -1] = tmp;
		}

		sleep(1);
		printf("reverse_msgbuf :%s\n", msg->buf);
		sem_post(&sem_printf);
	}
}

void* printf_msgbuf(void* arg)
{
	msg_t *msg = (msg_t *)arg;
	while(1)
	{
		sem_wait(&sem_printf);
		printf("printf_msgbuf :***********\n");
		printf("printf_msgbuf :%s\n", msg->buf);
		sem_post(&sem_reverse);
	}
}

int main(int argc, const char *argv[])
{
	msg_t msg = {"123456789", 9};
	pthread_t tid[2];

	sem_init(&sem_printf, 0, 1);
	sem_init(&sem_reverse, 0, 0);
	pthread_create(&tid[1], NULL, printf_msgbuf, (void *)&msg);
	pthread_create(&tid[0], NULL, reverse_msgbuf, (void *)&msg);

	pause();

	return 0;
}
