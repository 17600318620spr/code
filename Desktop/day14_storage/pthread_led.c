#include "data_global.h"

extern int m0_fd;
extern pthread_mutex_t mutex_led;
extern pthread_cond_t cond_led;
extern unsigned char dev_led_cmd;


//:A9LED模块线程.
void *pthread_led(void *arg)
{
	printf("pthread_led\n");
#if 0
	5.	open(dev_led,  )
	6.	pthread_cond_wait (cond_led,  );
	7.	获取dev_led_mask（控制标志）
	8.	通过ioctl（）控制led
#endif 

        while(1)
        {
                pthread_mutex_lock(&mutex_led);
                pthread_cond_wait(&cond_led, &mutex_led);
                write(m0_fd, &dev_led_cmd, 1);
                printf("led pthread is running....\n");
                pthread_mutex_unlock(&mutex_led);
        }
}

