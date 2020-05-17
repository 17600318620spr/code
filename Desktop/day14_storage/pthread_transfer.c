#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>
#include <pthread.h>
#include "data_global.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include "uart_api.c"

void print_storage_allenv_info(struct storage_info *s_info);

extern struct env_info_clien_addr all_info_RT;

/*
 * "uart_api.c"
 *
int set_com_config(int fd, int baud_rate, int data_bits, char parity, int stop_bits)
{
        struct termios new_cfg, old_cfg;
        int speed;
      
        if (tcgetattr(fd, &old_cfg) != 0){
                perror("tcgetattr");
                return -1;
        }

        new_cfg =old_cfg;

        cfmakeraw(&new_cfg);
        new_cfg.c_cflag &= ~CSIZE;

        switch (baud_rate)
        {
                case 2400:{
                                  speed = B2400;
                                  break; 
                          }
                case 4800:{
                                  speed = B4800;
                                  break;
                          }
                case 9600:{
                                  speed = B9600;
                                  break;
                          }
                case 19200:{
                                   speed = B19200;
                                   break;
                           }
                case 38400:{
                                   speed = B38400;
                                   break;
                           }
                default:
                case 115000:{
                                    speed = B115200;
                                    break;
                            }
        }

        cfsetispeed(&new_cfg, speed);
        cfsetospeed(&new_cfg, speed);

        switch (data_bits)
        {
                case 7:{
                               new_cfg.c_cflag |= CS7;
                               break;
                       }   
                default:        
                case 8:{
                               new_cfg.c_cflag |= CS8;
                               break;
                       }
        }

        switch (parity)
        {
                default:
                case 'n':
                case 'N':{
                                 new_cfg.c_cflag &= ~PARENB;
                                 new_cfg.c_iflag &= ~INPCK;
                                 break;
                         }
                case 'o':
                case 'O':{
                                 new_cfg.c_cflag |= (PARODD |PARENB);
                                 new_cfg.c_iflag |= INPCK;
                                 break;
                         }
                case 'e':
                case 'E':{
                                 new_cfg.c_cflag |= PARENB;
                                 new_cfg.c_cflag &= ~PARODD;
                                 new_cfg.c_iflag |= INPCK;
                                 break;
                         }
                case 's':
                case 'S':{
                                 new_cfg.c_cflag &= ~PARENB;
                                 new_cfg.c_cflag &= ~CSTOPB;
                                 break;
                         }
        }

        switch (stop_bits)
        {
                default:
                case 1:{
                               new_cfg.c_cflag &= ~CSTOPB;
                               break;
                       }       
                case 2:{
                               new_cfg.c_cflag |= CSTOPB;
                               break;
                       }
        }

        new_cfg.c_cc[VTIME] = 0;
        new_cfg.c_cc[VMIN] = 1;
        tcflush(fd, TCIFLUSH);
        if ((tcsetattr(fd, TCSANOW, &new_cfg)) != 0)
        {
                perror("tcsetattr");
                return -1;
        }
        return 0;
}

int open_port(char *com_port)
{
        int fd;

        fd = open(com_port, O_RDWR|O_NOCTTY|O_NDELAY);
        if (fd < 0){
                perror("open serial port");
                return -1;
        }

        if (fcntl(fd, F_SETFL, 0) < 0){
                perror("fcntl F_SETFL\n");
        }
      
        if (isatty(fd) == 0){
                perror("This is not a terminal device");
        }
        
        return fd;
}
*/

int recvDats(int fd,unsigned char *pBuf,int datalen)
{   
        int curlen= 0;   
        int reallen= 0;   
        while(curlen < datalen)    
        {        
                reallen = read(fd,pBuf+curlen, datalen-curlen);          
                if(reallen >= 0){           
                        curlen+=reallen;        
                }else{          
                        //printf("%s %d:%s\n",__FUNCTION__,__LINE__,"uart recv err"); 
                        return -1;       
                }
        }
        return 0;
}

//:接收M0数据线程.
void *pthread_transfer(void *arg)
{
        printf("pthread_transfer\n");

        int fd = open_port("/dev/ttyUSB0");
        if(fd < 0){
                printf("open failed\n");
//                return -1;
        }
        set_com_config(fd, 115200, 8, 'N', 1);

        char buf[sizeof(struct storage_info)+2]={0};
        printf("sizeof(buf) = %d.\n",sizeof(buf));

        while(1){
                memset(buf,0,sizeof(buf));
                recvDats(fd,&buf[0],1);
                if(buf[0] != 0x55){
                        continue;
                }
                recvDats(fd,&buf[1],1);
                if(buf[1] != 0xaa){
                        continue;
                }
                recvDats(fd,&buf[2],sizeof(buf)-2);
                memcpy(&(all_info_RT.storage_no[1]),buf+2,sizeof(buf)-2);
                print_storage_allenv_info(&(all_info_RT.storage_no[1]));
                sleep(1);
        }
        close(fd);
}

void print_storage_allenv_info(struct storage_info *s_info)
{
        int i = 0;
        printf("******************************************\n");
        printf("storage_status = %d \n",s_info->storage_status);
        printf("led_status = %d \n",s_info->led_status);        
        printf("buzzer_status = %d \n",s_info->buzzer_status);
        printf("fan_status = %d \n",s_info->fan_status);
        printf("seg_status = %d \n",s_info->seg_status);
        printf("x = %d \n",s_info->x);
        printf("y = %d \n",s_info->y);
        printf("z = %d \n",s_info->z);

        printf("temperature = %f \n",s_info->temperature);

        printf("temperatureMIN = %f \n",s_info->temperatureMIN);
        printf("temperatureMAX = %f \n",s_info->temperatureMAX);
        printf("humidity = %f \n",s_info->humidity);
        printf("humidityMIN = %f \n",s_info->humidityMIN);
        printf("humidityMAX = %f \n",s_info->humidityMAX);      

        printf("illumination = %f \n",s_info->illumination);
        printf("illuminationMIN = %f \n",s_info->illuminationMIN);
        printf("illuminationMAX = %f \n",s_info->illuminationMAX);

        printf("battery = %f \n",s_info->battery);
        printf("adc = %f \n",s_info->adc);
#if 0   
        for(i=0;i <GOODS_NUM;i++){
                printf("goods_info[%d].type = %u\n",i,s_info->goods_info[i].goods_type);
                printf("goods_info[%d].count = %u\n",i,s_info->goods_info[i].goods_count);
        }       
#endif
}
