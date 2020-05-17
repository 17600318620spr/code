
CROSS_COMPILE=arm-linux-
CC=$(CROSS_COMPILE)gcc
#CC=gcc
CFLAGS= -c -g 
#LDFLAGS= -lpthread -L ./lib -lsqlite3
LDFLAGS= -lpthread

OBJS=main.o data_global.o pthread_transfer.o pthread_analysis.o \
	pthread_client_request.o pthread_buzzer.o pthread_led.o\
	pthread_camera.o pthread_sqlite.o pthread_refresh.o pthread_sms.o

our_storage :$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
	mv *o ./obj
$(OBJS):%.o:%.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY:clean
clean:
#	rm *.o smart_storage -rf 
	rm *.o our_storage -rf 

