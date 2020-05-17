#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

struct node 
{
	int n_number;
	struct node *n_next;
}*head = NULL;

static void cleanup_handler(void *arg)
{
	printf("Cleanup handler of second thread.\n");
	free(arg);
	(void)pthread_mutex_unlock(&mtx);
}

static void *thread_func(void *arg)
{
	struct node *p = NULL;
	pthread_cleanup_push(cleanup_handler, p);
	while (1) 
	{
		pthread_mutex_lock(&mtx);
		//这个mutex主要是用来保证pthread_cond_wait的并发性
		while(head == NULL) 
		{ 
			pthread_cond_wait(&cond, &mtx);
		}
		p = head;
		head = head->n_next;
		printf("Got %d from front of queue\n", p->n_number);
		free(p);
		pthread_mutex_unlock(&mtx); //临界区数据操作完毕，释放互斥锁
	}
	pthread_cleanup_pop(0);
	return 0;
}

int main(void)
{
	pthread_t tid;
	int i;
	struct node *p;

	/*
	 * 子线程会一直等待资源,类似生产者和消费者,
	 * 但是这里的消费者可以是多个消费者,而不仅仅支持普通的单个消费者;
	 * 这个模型虽然简单，但是很强大
	 */
	pthread_create(&tid, NULL, thread_func, NULL); 

	for (i = 0; i < 10; i++) 
	{
		p = malloc(sizeof(struct node));
		p->n_number = i;

		pthread_mutex_lock(&mtx); //需要操作head这个临界资源，先加锁，
		p->n_next = head;
		head = p;
		pthread_mutex_unlock(&mtx); //解锁
		pthread_cond_signal(&cond);
		sleep(1);
	}
	printf("thread 1 wanna end the line.So cancel thread 2.\n");

	pthread_cancel(tid);
	pthread_join(tid, NULL);

	printf("All done -- exiting.\n");
	return 0;
}
