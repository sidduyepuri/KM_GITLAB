#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
char msg[] = "Hello World";
int x=1;
void *thread_fun(void *arg);
// main thread
int main()
{
	int ret;
	pthread_t abc;
	void *retval;
	ret = pthread_create(&abc,NULL,thread_fun,(void *)msg);
	printf("id=%d\n",abc);
	if (ret < 0){
		perror("pthread create fail:");
		exit(0);
	}
	printf("hello\n");
	while(x<=100)
	{
		if(x%2==1)
		{
			printf("odd=%d\n",x);
			x++;
		}
		else
			sleep(1);
	}
	//pid_t tid = syscall(SYS_gettid);
	//printf("Thread ID: %d\n",syscall(SYS_gettid));
	ret = pthread_join(abc,&retval);
	if (ret < 0){
		perror("pthread join fail:");
		exit(0);
	}
	printf("excited with msg:%s\n",retval);
	return 0;
}

// thread handler
void *thread_fun(void *arg)
{
	//	printf("msg:%s\n",(char *)arg);
	//getchar();
	//pid_t tid = syscall(SYS_gettid);
	//printf("Thread ID: %d\n", tid);
	//printf("gettid=%d\n",gettid());
	while(x<=100)
	{
		if(x%2==0)
		{
			printf("even=%d\n",x);
			x++;
		}
		else{
			sleep(1);
		}
	}
//	sleep(5);
	pthread_exit("Thanks for CPU utilizing time cycles");	
}

