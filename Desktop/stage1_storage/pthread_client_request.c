#include "data_global.h"

extern int msgid;
extern key_t msg_key;

extern pthread_mutex_t mutex_client_request,
	   					mutex_led;
extern pthread_cond_t cond_client_request,
	   					cond_led;

extern char recive_phone[12],
	   		center_phone[12];

struct msg msgbuf;


void *pthread_client_request(void *arg)
{
	if((msg_key=ftok("/tmp", 'g'))<0)
	{
		perror("ftok");
		exit(0);
	}

	msgid=msgget(msg_key, IPC_CREAT|IPC_EXCL|0666);
	if(msgid==-1)
	{
		if(errno==EEXIST)
		{
			msgid=msgget(msg_key, 0777);
		}
		else
		{
			perror("msgget");
			exit(1);
		}
	}
	puts("pthread_client_request");

	while(1)
	{
		bzero(&msgbuf, sizeof(msgbuf));
		puts("wait from client request");
		msgrcv(msgid, &msgbuf, sizeof(msgbuf)-sizeof(long), 1L, 0);
		printf("Get %ldL msg\n", msgbuf.msgtype);
		printf("text[0]=%#x\n", msgbuf.text[0]);

/*
   switch函数部分完成了对不同消息类型的不同处理:
   1L为唤醒A9上的led线程，同时需要对led命令掩码进行赋值，程序规定去消息正文的第一个字节作为命令控制字；
   2L为唤醒A9上的蜂鸣器进程，同时对蜂鸣器命令掩码进行赋值；
   3L是唤醒摄像头线程进行抓拍，同时对抓拍命令掩码进行赋值，这里的抓拍命令掩码是抓拍的照片数量；
   4L是向M0发送数据，这里将发送命令掩码直接写入ZigBee串口，没有另外唤醒发送线程；
   5L根据消息正文对相应的环境参数阈值进行设置，唤醒共享内存刷新线程。
*/

		switch(msgbuf.msgtype)
		{
		case 1L:
			puts("hello led");
			break;
		case 2L:
			puts("hello beep");
			break;
		case 3L:
			puts("hello camera");
			break;
		case 4L:
			puts("hello M0");
			break;
		case 5L:
			puts("set env data");
			printf("temMAX:%d\n", *((int *)&msgbuf.text[1]));
			printf("temMIN: %d\n",*((int *)&msgbuf.text[5]));
			printf("humMAX: %d\n",*((int *)&msgbuf.text[9]));
			printf("humMAX: %d\n",*((int *)&msgbuf.text[13]));
			printf("illMAX: %d\n",*((int *)&msgbuf.text[17]));
			printf("illMAX: %d\n",*((int *)&msgbuf.text[21]));
			break;
		case 6L:
			pthread_mutex_lock(&mutex_led);
			pthread_cond_wait(&cond_led, &mutex_led);
			puts("hello led");
			pthread_mutex_unlock(&mutex_led);
			pthread_cond_broadcast(&cond_led);
			break;
		case 10L:
/*
			int i = 0 , j = 0 ;
			for(i = 0 ; i < 11; i++){
				recive_phone[i] = msgbuf.text[i]; 	
			}
			recive_phone[i] = '\0';
			printf("recive:%s\n",recive_phone);
			for(j = 0 ;msgbuf.text[i] != '\0' && j < 12; i++, j++)
			{
				center_phone[j] =  msgbuf.text[i];
			}
			center_phone[j] = '\0';
			printf("center:%s\n",center_phone);
#if 0
			pthread_mutex_lock (&mutex_slinklist);
			sqlite_InsertLinknode (ENV_UPDATE, all_info_RT, sto_no, 0);//0,0分别是仓库号和货物种类号
			pthread_mutex_unlock (&mutex_slinklist);
			pthread_cond_signal (&cond_sqlite);
#endif 
*/
			break;
		default:
			break;
		}
	}
}
