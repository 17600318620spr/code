//P136
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *thrd_func(void *arg)
{
	int thrd_num=(int)arg;
	int ret;

	ret=pthread_mutex_lock(&mutex);
	if(ret)
	{
		printf("Thread %d lock failed\n", thrd_num);
		pthread_exit(NULL);
	}
	printf("Thread %d is starting\n", thrd_num);
//	thrd_num=thrd_num+1;
	printf("Thread %d is finished\n", thrd_num);
	pthread_mutex_unlock(&mutex);

	pthread_exit(NULL);
}

int main(int argc, const char *argv[])
{
	pthread_t thread[3];
	int no=0, ret;
	void *thrd_ret;

	pthread_mutex_init(&mutex, NULL);
	for(no=0; no<3; no++)
	{
		/* 创建多线程 */
		ret=pthread_create(&thread[no], NULL, thrd_func, (void *)no);
		if(ret!=0)
		{
			printf("Create thread %d failed\n", no);
			exit(ret);
		}
	}

	printf("Create threads success\n Waiting for threads to finish...\n");

	for(no=0; no<3; no++)
	{
		/* 等待线程结束 */
		ret=pthread_join(thread[no], &thrd_ret);
		if(!ret)
		{
			printf("Thread %d joined\n", no);
		}
		else
		{
			printf("Thread %d join failed\n", no);
		}
	}
	pthread_mutex_destroy(&mutex);
	
	return 0;
}

