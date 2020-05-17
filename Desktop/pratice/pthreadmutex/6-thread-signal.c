/**
  * @file pthread_mutex.c
  */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include <pthread.h>
 
 /* 定义互斥量 */
 pthread_mutex_t mutex;
 /* 互斥量属性 */
 pthread_mutexattr_t mutex_attr;
 /* 全局资源 */
 int reource_money;
 
 /* 条件变量 */
 pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
 
 void err_exit(const char *err_msg)
 {
     printf("error:%s\n", err_msg);
     exit(1);
 }
 
 /* 线程函数 */
 void *thread_fun(void *arg)
 {
     while (1)
     {   /* 加锁 */
         pthread_mutex_lock(&mutex);
         /* 条件变量 */
         while (reource_money > 0) {
             printf("子线程坐等reource_money等于0...\n");
             pthread_cond_wait(&cond, &mutex);
         }
 
         printf("子线程进入临界区查看reource_money\n");
         if (reource_money == 0) {
             reource_money += 300;
             printf("子线程:reource_money = %d\n", reource_money);
         }
         /* 解锁 */
         pthread_mutex_unlock(&mutex);
         sleep(1);
puts("=======================================================================");
     }
     return NULL;
 }
 
 int main(void)
 {
     pthread_t tid;
 
     /* 初始化互斥量 */
     if (pthread_mutex_init(&mutex, NULL) == -1)
         err_exit("pthread_mutex_init()");
     /* 创建一个线程 */
     if (pthread_create(&tid, NULL, thread_fun, NULL)== -1)
         err_exit("pthread_create()");

     reource_money = 1000;
     while (1)
     {
         /* 加锁 */
         pthread_mutex_lock(&mutex);
         if (reource_money > 0)
         {
             reource_money -= 100;
             printf("主线程:reource_money = %d\n", reource_money);
         }
         /* 解锁 */
         pthread_mutex_unlock(&mutex);
puts("-------------------------------------------------------------------------");
         /* 如果reource_money = 1，就通知子线程 */
         if (reource_money == 0)
         {
             printf("main thread 通知子线程\n");
             pthread_cond_signal(&cond);
         }
puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
         sleep(1);
     }
 
     return 0;
 }
