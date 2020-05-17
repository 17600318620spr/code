#include "data_global.h"

void release_pthread_resource(int signo);

extern pthread_mutex_t mutex_client_request,
	   					mutex_refresh,
						mutex_sqlite,
						mutex_transfer,
						mutex_analysis,
						mutex_sms,
						mutex_buzzer,
						mutex_led,
						mutex_camera;

extern pthread_cond_t cond_client_request,
	   					cond_refresh,
						cond_sqlite,
						cond_transfer,
						cond_analysis,
						cond_sms,
						cond_buzzer,
						cond_led,
						cond_camera;

extern struct env_info_clien_addr all_info_RT;

extern int msgid;
extern int shmid;
extern int semid;

pthread_t id_client_request,
		  id_refresh,
		  id_sqlite,
		  id_transfer,
		  id_analysis,
		  id_sms,
		  id_buzzer,
		  id_led,
		  id_camera;

int main(int argc, const char *argv[])
{
	pthread_mutex_init(&mutex_client_request, NULL),
	pthread_mutex_init(&mutex_refresh, NULL);
	pthread_mutex_init(&mutex_sqlite, NULL);
	pthread_mutex_init(&mutex_transfer,NULL);
	pthread_mutex_init(&mutex_analysis,NULL);
	pthread_mutex_init(&mutex_sms,NULL);
	pthread_mutex_init(&mutex_buzzer,NULL);
	pthread_mutex_init(&mutex_led,NULL);
	pthread_mutex_init(&mutex_camera,NULL);

	signal(SIGINT, release_pthread_resource);

	pthread_cond_init(&cond_client_request, NULL);
	pthread_cond_init(&cond_refresh,NULL);
	pthread_cond_init(&cond_sqlite,NULL);
	pthread_cond_init(&cond_transfer,NULL);
	pthread_cond_init(&cond_analysis,NULL);
	pthread_cond_init(&cond_sms,NULL);
	pthread_cond_init(&cond_buzzer,NULL);
	pthread_cond_init(&cond_led,NULL);
	pthread_cond_init(&cond_camera,NULL);

	pthread_create(&id_client_request, NULL, pthread_client_request, NULL);
	pthread_create(&id_refresh, 	   NULL, pthread_refresh, 		NULL);  			
	pthread_create(&id_sqlite, 		   NULL, pthread_sqlite, 		NULL);  			
	pthread_create(&id_transfer, 	   NULL, pthread_transfer, 		NULL);  	
	pthread_create(&id_analysis, 	   NULL, pthread_analysis, 		NULL); 
	pthread_create(&id_sms,			   NULL, pthread_sms, 			NULL);  	
	pthread_create(&id_buzzer, 		   NULL, pthread_buzzer, 		NULL);	 
	pthread_create(&id_led,			   NULL, pthread_led, 			NULL);  	
	pthread_create(&id_camera, 		   NULL, pthread_camera, 		NULL); 	

	pthread_join(id_client_request, NULL); 	puts("pthread1");
	pthread_join(id_refresh, NULL); 		puts("pthread2");
	pthread_join(id_sqlite,NULL);			puts("pthread3");
	pthread_join(id_transfer,NULL);			puts("pthread4");
	pthread_join(id_analysis,NULL);			puts("pthread5");
	pthread_join(id_sms,NULL);				puts("pthread6");
	pthread_join(id_buzzer,NULL);			puts("pthread7");
	pthread_join(id_led,NULL);				puts("pthread8");
	pthread_join(id_camera,NULL);         	puts("pthread9");

	return 0;
}

void release_pthread_resource(int signo)
{
	pthread_mutex_destroy(&mutex_client_request);
	pthread_mutex_destroy(&mutex_refresh);
	pthread_mutex_destroy(&mutex_sqlite);   
	pthread_mutex_destroy(&mutex_transfer);   
	pthread_mutex_destroy(&mutex_analysis);   
	pthread_mutex_destroy(&mutex_sms);   
	pthread_mutex_destroy(&mutex_buzzer);   
	pthread_mutex_destroy(&mutex_led);   
	pthread_mutex_destroy(&mutex_camera); 

	pthread_cond_destroy(&cond_client_request);
	pthread_cond_destroy(&cond_refresh);
 	pthread_cond_destroy(&cond_sqlite);
 	pthread_cond_destroy(&cond_transfer);
 	pthread_cond_destroy(&cond_analysis);
 	pthread_cond_destroy(&cond_sms);
 	pthread_cond_destroy(&cond_buzzer);
 	pthread_cond_destroy(&cond_led);
 	pthread_cond_destroy(&cond_camera);

	pthread_detach(id_client_request);
	pthread_detach(id_refresh);
	pthread_detach(id_sqlite);
	pthread_detach(id_transfer);
	pthread_detach(id_analysis);
	pthread_detach(id_sms);
	pthread_detach(id_buzzer);
	pthread_detach(id_led);
	pthread_detach(id_camera);

	puts("all of the pthreads are detached!");

	msgctl(msgid, IPC_RMID, NULL);
	shmctl(shmid, IPC_RMID, NULL);
	semctl(semid, 1, IPC_RMID, NULL);

	exit(0);
}
