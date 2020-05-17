
#include "data_global.h"


/*********************************************************
	data_global.c : 
	
		全局的互斥体声明
		全局的条件锁声明声明
		全局的id和key信息声明
		全局的消息队列发送函数声明
		
*********************************************************/



pthread_mutex_t mutex_client_request,
        	mutex_refresh,
        	mutex_sqlite,
	        mutex_transfer,
	        mutex_analysis,
	        mutex_sms,
	        mutex_buzzer,
	        mutex_led,
	        mutex_camera;

pthread_cond_t  cond_client_request,
        	cond_refresh,
        	cond_sqlite,
	       	cond_transfer,
	       	cond_analysis,
	       	cond_sms,
	       	cond_buzzer,
	       	cond_led,
	       	cond_camera;

int msgid;
int shmid;
int semid;
key_t key; //msg_key
key_t shm_key;
key_t sem_key;

int m0_fd;
unsigned char dev_led_cmd;
unsigned char dev_buzzer_cmd;
unsigned char dev_seg_cmd;
unsigned char dev_fan_cmd;

char recive_phone[12] = "0";
char center_phone[12] = "0";

struct env_info_clien_addr env_info_clien_addr_s;
struct env_info_clien_addr all_info_RT;

int send_msg_queue(long type,unsigned char text)
{
	struct msg msgbuf;
	msgbuf.type = 1L;
	msgbuf.msgtype = type;
	msgbuf.text[0] = text;

	if(msgsnd(msgid,&msgbuf,sizeof(msgbuf) - sizeof(long),0) == -1){
		perror("fail to msgsnd type2");
		exit(1);
	}

	return 0;
}

