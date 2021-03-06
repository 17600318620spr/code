/*************************************************************************
	#	 FileName	: flaglock.c
	#	 Author		: fengjunhui 
	#	 Email		: 18883765905@163.com 
	#	 Created	: 2017年12月22日 星期五 09时30分42秒
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define N 64
typedef struct message{
	char buf[N];
	int len;
//	int busy_flag;
}msg_t;

int flag = 0;
pthread_mutex_t mymutex;
pthread_cond_t mycond; //= PTHREAD_COND_INITIALIZER;

void* reverse_msgbuf(void* arg)
{
	msg_t *msg = (msg_t *)arg;
	int i = 0;
	char tmp;
	while(1){
		pthread_mutex_lock(&mymutex);
		printf("reverse_msgbuf -------------\n");
		while(flag != 0){
			pthread_cond_wait(&mycond, &mymutex);
		}

		for(i = 0; i < msg->len/2; i++)
		{
			tmp			 			  = msg->buf[i];
			msg->buf[i]  			  = msg->buf[msg->len - i - 1];
			msg->buf[msg->len - i -1] = tmp;
		}

		printf("reverse_msgbuf :%s\n",msg->buf);
		flag = 1;
		pthread_mutex_unlock(&mymutex);
		pthread_cond_broadcast(&mycond);
//		sleep(1);
	}
}

void* printf_msgbuf(void* arg)
{
	msg_t *msg = (msg_t *)arg;
	while(1)
	{
		pthread_mutex_lock(&mymutex);
		printf("printf_msgbuf :***********\n");
		while(flag != 1)
		{
			pthread_cond_wait(&mycond, &mymutex);
		}
		printf("printf_msgbuf :%s\n", msg->buf);
		flag = 0;
		pthread_mutex_unlock(&mymutex);
		pthread_cond_broadcast(&mycond);
//		sleep(1);
	}
}

int main(int argc, const char *argv[])
{
	//msg_t msg = {"123456789",9,0};
	msg_t msg = {"123456789", 9};

	pthread_t tid[2];
	
	pthread_cond_init(&mycond, NULL);
	pthread_mutex_init(&mymutex, NULL);

	pthread_create(&tid[0], NULL, reverse_msgbuf, (void *)&msg);
	pthread_create(&tid[1], NULL, printf_msgbuf, (void *)&msg);

	pause();

	return 0;
}
