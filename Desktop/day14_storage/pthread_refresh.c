#include "data_global.h"
#include "sem.h"

#define N 1024

extern int shmid,
           msgid,
           semid;

extern key_t shm_key,
             msg_key,
             sem_key;

extern pthread_mutex_t mutex_refresh;
extern pthread_cond_t cond_refresh;
						
extern struct env_info_clien_addr all_info_RT;

struct shm_addr
{
	char cgi_status;
	char qt_status;
	struct env_info_clien_addr rt_status;
};
struct shm_addr *shm_buf;


int file_env_info_struct(struct env_info_clien_addr *rt_status, int storage_id);
static char *my_itoa(int n);


void *pthread_refresh(void *arg)
{
	if((sem_key=ftok("/tmp", 'i'))<0)
	{
		perror("ftok");
		exit(0);
	}

	semid=semget(sem_key, 1, IPC_CREAT|IPC_EXCL|0666);
	if(semid==-1)
	{
		if(errno==EEXIST)
		{
			semid=semget(sem_key, 1, 0777);
		}
		else
		{
			perror("semget");
			exit(-1);
		}
	}
	else
	{
		init_sem(semid, 0, 1);
	}

	if((shm_key=ftok("/tmp", 'i'))<0)
	{
		perror("ftok");
		exit(0);
	}

	shmid=shmget(shm_key, N, IPC_CREAT|IPC_EXCL|0666);
	if(shmid==-1)
	{
		if(errno==EEXIST)
		{
			shmid=shmget(shm_key, N, 0777);
		}
		else
		{
			perror("shmget");
			exit(-1);
		}
	}

	if((shm_buf=(struct shm_addr *)shmat(shmid, NULL, 0))==(void *)-1)
	{
		perror("shmat");
		exit(-1);
	}
	puts("pthread_refresh.......>>>>>>");

//	bzero(&shm_buf, sizeof(struct shm_addr));
	bzero(shm_buf, sizeof(struct shm_addr));

	while(1)
	{
		file_env_info_struct(&shm_buf->rt_status, 1);
		sem_p(semid, 0);
		shm_buf->rt_status=all_info_RT;
		sleep(2);
		sem_v(semid, 0);
	}
/*	
	1.使用ftok( ,  )函数获得唯一键值
	2.使用shmget创建共享内存
	3.等待唤醒	pthread_cond_wait (cond_refresh,   );
	4.写数据
	说明：创建的共享内存需要和相应的CGI程序共享，故需要在这里使用和Cgi相同的键值去创建，
	同时对共享内存的使用时需要使用信号量进行同步。
*/
}

int file_env_info_struct(struct env_info_clien_addr *rt_status, int storage_id)
{
	int env_info_size=sizeof(struct env_info_clien_addr);

	
	rt_status->storage_no[storage_id].storage_status=0x01;
	rt_status->storage_no[storage_id].led_status=0x03;
	rt_status->storage_no[storage_id].buzzer_status=0x03;
	rt_status->storage_no[storage_id].fan_status=0x03;
	rt_status->storage_no[storage_id].seg_status=0x05;

/*
	rt_status->storage_no[storage_id].storage_status=0x01;
	rt_status->storage_no[storage_id].led_status=my_itoa(2);
	rt_status->storage_no[storage_id].buzzer_status=my_itoa(3);
	rt_status->storage_no[storage_id].fan_status=my_itoa(4);
	rt_status->storage_no[storage_id].seg_status=my_itoa(5);
*/

        static int i=1;
	rt_status->storage_no[storage_id].x=10;
	rt_status->storage_no[storage_id].y=20;
	rt_status->storage_no[storage_id].z=30;

	rt_status->storage_no[storage_id].temperature=10.0;
	rt_status->storage_no[storage_id].temperatureMAX=2.0;
	rt_status->storage_no[storage_id].temperatureMIN=20.0;
	rt_status->storage_no[storage_id].humidity=20.0;
	rt_status->storage_no[storage_id].humidityMIN=10.0;
	rt_status->storage_no[storage_id].humidityMAX=30.0;
	rt_status->storage_no[storage_id].illumination=20.0;
	rt_status->storage_no[storage_id].illuminationMIN=10.0;
	rt_status->storage_no[storage_id].illuminationMAX=50.0;
	rt_status->storage_no[storage_id].battery=90.0;
	rt_status->storage_no[storage_id].adc=40.0;

	rt_status->storage_no[storage_id].goods_info[0].goods_type=0x5;
	rt_status->storage_no[storage_id].goods_info[1].goods_count=15;

	return 0;
}



/*
 * 功能：整数转换为字符串 
 * char s[] 的作用是存储整数的每一位 
 */ 

static char *my_itoa(int n)
{
	static char s[100];
/*
	int i=0, isNegative=0;
	static char s[100];

	if((isNegative=n)<0)
	{
		n=-n;
	}

	do
	{
		s[i++]=n%10+'0';
		n=n/10;
	}while(n>0);

	if(isNegative<0)
	{
		s[i++]='-';
	}
	s[i]='\0';
*/
	sprintf(s, "%d", n);

	return s;
}

