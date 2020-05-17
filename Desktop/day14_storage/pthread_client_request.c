#include "data_global.h"

extern int msgid;
extern key_t key;

extern pthread_mutex_t mutex_client_request,
        		mutex_refresh,
        		mutex_sqlite,
	        	mutex_transfer,
	        	mutex_analysis,
	        	mutex_sms,
	        	mutex_buzzer,
	         	mutex_led,
	         	mutex_camera;

extern pthread_cond_t  cond_client_request,
        		cond_refresh,
        		cond_sqlite,
	        	cond_transfer,
	        	cond_analysis,
	        	cond_sms,
	        	cond_buzzer,
	         	cond_led,
	         	cond_camera;

extern char recive_phone[12];
extern char center_phone[12];

extern int m0_fd;
extern unsigned char dev_led_cmd;
extern unsigned char dev_buzzer_cmd;
extern unsigned char dev_seg_cmd;
extern unsigned char dev_fan_cmd;

struct msg msgbuf;



//:处理消息队列里请求的线程.
void *pthread_client_request(void *arg)
{
	if((key = ftok("/tmp",'g')) < 0){
		perror("ftok failed .\n");
		exit(-1);
	}

	msgid = msgget(key,IPC_CREAT|IPC_EXCL|0666);
	if(msgid == -1)	{
		if(errno == EEXIST){
			msgid = msgget(key,0777);
		}else{
			perror("fail to msgget");
			exit(1);
		}
	}
        printf("pthread_client_request\n");


        int m0_fd = open_port("/dev/ttyUSB0");
        if(m0_fd < 0){
                printf("open failed\n");
                //return -1;
        }
        set_com_config(m0_fd, 115200, 8, 'N', 1);


	while(1){
		bzero(&msgbuf,sizeof(msgbuf));
		printf("wait form client request...\n");
		msgrcv (msgid, &msgbuf, sizeof(msgbuf) - sizeof(long), 1L, 0);
		printf ("Get %ldL msg\n", msgbuf.msgtype);
		printf ("text[0] = %#x\n", msgbuf.text[0]);

		//1L - 5L为线程分类的消息类型
		switch(msgbuf.msgtype){
		case 1L:
			pthread_mutex_lock(&mutex_led);
			dev_led_cmd=msgbuf.text[0];
			printf("hello led\n");
			pthread_cond_signal(&cond_led);
			pthread_mutex_unlock(&mutex_led);
			break;
		case 2L:
			printf("hello beep\n");
			dev_buzzer_cmd=msgbuf.text[0];
			write(m0_fd, &dev_buzzer_cmd, 1);
			break;
		case 3L:
			printf("hello seg\n");
			dev_seg_cmd=msgbuf.text[0];
			write(m0_fd, &dev_seg_cmd, 1);
			break;
		case 4L:
			printf("hello fan\n");
			dev_fan_cmd=msgbuf.text[0];
			write(m0_fd, &dev_fan_cmd, 1);
			break;
		case 5L:
			printf("set env data\n");
			printf("temMAX: %d\n",*((int *)&msgbuf.text[1]));
			printf("temMIN: %d\n",*((int *)&msgbuf.text[5]));
			printf("humMAX: %d\n",*((int *)&msgbuf.text[9]));
			printf("humMAX: %d\n",*((int *)&msgbuf.text[13]));
			printf("illMAX: %d\n",*((int *)&msgbuf.text[17]));
			printf("illMAX: %d\n",*((int *)&msgbuf.text[21]));
			break;
		case 6L:
			pthread_mutex_lock(&mutex_led);
			pthread_cond_wait(&cond_led,&mutex_led);
			printf("hello led\n");
			pthread_mutex_unlock(&mutex_led);
			pthread_cond_broadcast(&cond_led);
			break;
		case 10L:
			{
				int i = 0, j = 0;
				for(i = 0; i < 11; i++)
				{
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
			}
			break;
		default:
			break;
		}
	}

}

#if 0

switch函数部分完成了对不同消息类型的不同处理:
1L为唤醒A9上的led线程，同时需要对led命令掩码进行赋值，程序规定去消息正文的第一个字节作为命令控制字；
2L为唤醒A9上的蜂鸣器进程，同时对蜂鸣器命令掩码进行赋值；
3L是唤醒摄像头线程进行抓拍，同时对抓拍命令掩码进行赋值，这里的抓拍命令掩码是抓拍的照片数量；
4L是向M0发送数据，这里将发送命令掩码直接写入ZigBee串口，没有另外唤醒发送线程；
5L根据消息正文对相应的环境参数阈值进行设置，唤醒共享内存刷新线程。

#endif 





