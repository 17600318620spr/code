
#include "data_global.h"

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node *next;
}listnode, *linklist;


extern linklist list_create()
{
	linklist H;
	H=(linklist)malloc(sizeof(listnode));

	if(NULL==H)
	{
		perror("malloc");
		exit(-1);
	}
	H->data=0;
	H->next=NULL;

	return H;
}

extern pthread_mutex_t mutex_sqlite;
						
extern pthread_cond_t cond_sqlite;
						
extern struct env_info_clien_addr env_info_clien_addr_s;
extern struct env_info_clien_addr all_info_RT;

//:数据库线程.
void *pthread_sqlite(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex_sqlite);
		pthread_cond_wait(&cond_sqlite, &mutex_sqlite);
		pthread_mutex_unlock(&mutex_sqlite);

		while(1)
		{
/*
			env_info_clien_addr_s.storage_no[storage_id].temperature=20.0;
			env_info_clien_addr_s.storage_no[storage_id].humidity=30.0;
			env_info_clien_addr_s.storage_no[storage_id].illumination=40.0;

			all_info_RT.storage_no[storage_id].temperature=40.0;
			all_info_RT.storage_no[storage_id].humidity=50.0;
			all_info_RT.storage_no[storage_id].illumination=60.0;
*/
		}
	}

	printf("pthread_sqlite\n");
}
