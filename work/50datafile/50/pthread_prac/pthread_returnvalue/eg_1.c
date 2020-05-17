/* https://blog.csdn.net/guilanl/article/details/50150463
 *1. 定义一个 包含 线程函数的 参数和返回值的 数据结构。
 */

#include <stdio.h>
#include <pthread.h>

typedef struct thread_data
{
	int a;
	int b;
	int result;
}thread_data;

void *myThread(void *arg)
{
	thread_data *tdata=(thread_data *)arg;

	int 	 a=tdata->a;
	int 	 b=tdata->b;
	int result=a+b;

	tdata->result=result;
	pthread_exit(NULL);
}

int main(int argc, const char *argv[])
{
	pthread_t tid;
	thread_data tdata;

	tdata.a=10;
	tdata.b=32;

	pthread_create(&tid, NULL, myThread, (void *)&tdata);
	pthread_join(tid, NULL);

	printf("%d+%d=%d\n", tdata.a, tdata.b, tdata.result);
	
	return 0;
}
