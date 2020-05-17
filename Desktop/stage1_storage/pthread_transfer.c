
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>
#include <pthread.h>

#include "data_global.h"

//:接收M0数据线程.
void *pthread_transfer(void *arg)
{

	printf("pthread_transfer\n");
}

