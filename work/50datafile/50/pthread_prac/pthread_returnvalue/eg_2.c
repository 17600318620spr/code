/* https://blog.csdn.net/guilanl/article/details/50150463
 * 2. 用pthread_exit() 返回线程函数的返回值，用pthread_join 来接受 线程函数的返回值。
 */
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int something_worked(void)
{
	/* thread operation fail, so here's a silly example */
	void *p=malloc(10);
	free(p);

	return p?1:0;
}

void *myThread(void *result)
{
	if(something_worked())
	{
		*((int *)result)=42;
printf("222222222222\n");
		pthread_exit(result);
	}
	else
	{
printf("33333333333\n");
		pthread_exit(0);
	}
}

int main(int argc, const char *argv[])
{
	pthread_t tid;
	void *status=0;
	int result;

	pthread_create(&tid, NULL, myThread, &result);
	pthread_join(tid, &status);

	if(status!=0)
	{
		printf("%d\n", result);
	}
	else
	{
		printf("thread failed\n");
	}
	
	return 0;
}
