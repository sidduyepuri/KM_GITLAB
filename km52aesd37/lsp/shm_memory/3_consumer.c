#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include<signal.h>
sem_t *prod_lock,*cons_lock; 
int a,b;
int shmid,ret,fork_res;

int main()
{
	char *msg;
	prod_lock=sem_open("producer1",O_CREAT,0666,1);
	if(prod_lock==NULL)
	{
		perror("sem_open1");
		exit(0);
	}
	cons_lock=sem_open("consumer1",O_CREAT,0666,0);
	if(cons_lock==NULL)
	{
		perror("sem_open2");
		exit(1);
	}
	sem_getvalue(prod_lock,&a);	
	sem_getvalue(cons_lock,&b);	
	shmid=shmget(10,1024,0666);
	if(shmid<0)
	{
		perror("shmget");
		exit(0);
	}
	while(1)
	{
		sem_getvalue(prod_lock,&a);	
		sem_getvalue(cons_lock,&b);
		printf("cons:x:%d y:%d\n",a,b);
		sem_wait(cons_lock);
		msg=shmat(shmid,0,0);
		printf("CONSUMER Received from shared memory::: %s",msg);
		shmdt(msg);
		sem_post(prod_lock);	
	}
	return 0;
	
}
