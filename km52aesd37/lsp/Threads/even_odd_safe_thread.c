#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
void *even(void *arg);
void *odd(void *arg);
sem_t eve,od;
int main()
{
	int res;
	pthread_t even_thread,odd_thread;
	void *thread_result;

	sem_init(&eve,0,1);
	sem_init(&od,0,0);

	res=pthread_create(&even_thread,NULL,even,NULL);
	if(res!=0){
		printf("Thread creation Failed\n");
		exit(EXIT_FAILURE);
	}
	res=pthread_create(&odd_thread,NULL,odd,NULL);
	if(res!=0){
		printf("Thread creation Failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Wait for the pthread join\n");
	res=pthread_join(even_thread,&thread_result);
	if(res!=0){
		printf("Thread join Failed\n");
		exit(EXIT_FAILURE);
	}
	res=pthread_join(odd_thread,&thread_result);
	if(res!=0){
		printf("Thread join Failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined\n");
	exit(EXIT_FAILURE);
		
}
void *even(void *arg)
{
	int i=1;
	while(i<=100)
	{
		sem_wait(&eve);
		if(i%2==0)
			printf("Even=%d\n",i);
		i++;
		sem_post(&od);
	}
	pthread_exit("exit");
}
void *odd(void *arg)
{
	int i=1;
	while(i<100)
	{
		sem_wait(&od);
		if(i%2==1)
			printf("odd=%d\n",i);
		i++;
		sem_post(&eve);
	}
	pthread_exit("exit");
}
