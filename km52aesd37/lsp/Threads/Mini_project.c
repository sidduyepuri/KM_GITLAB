#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include<signal.h>
void *producer(void *arg);
void prod_sig(int sig);
void *consumer(void *arg);
void cons_sig(int sig);

pthread_t a_thread,b_thread;
int counter = 0;
char buffer[BUFSIZ +1];

int main() 
{
	int res;
	void *thread_result;
	res = pthread_create(&p_thread, NULL, producer, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&c_thread, NULL, consumer, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Wait for pthread_join\n");
	res = pthread_join(p_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_join(c_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined\n");
	exit(EXIT_SUCCESS);
}

//Producer Thread Implementation:
void *producer(void *arg)
{
	//Step 1: Initialize producer signal handler.
		(void) signal (SIGUSR1,prod_sig);
	//Step 2: Waiting for a signal from consumer thread inside infinite loop. Use pause () system call inside infinite loop and wait for a signal from consumer thread.
		while(1) {
			pause();
		}
}
//Producer Signal Handler Implementation:
void prod_sig(int sig)
{
	//Step 1: Producer start produce the data until the buffer is FULL. Use while () loop until Buffer is FULL.
	int in = 0,n=26; 
	char ch='A';
	while(n)
	{
		//	printf ("producer: counter:%d\n",counter); 
		//while(counter == 5);
		buffer[in]=ch;
		in = (in+1)%26;
		ch++;
		if (in == 0 )
		{
			ch='A';
			printf("p:%s\n",buffer);
		}
		n--;
	}
	//Step 2: Whenever buffer is FULL raise a signal to consumer thread.Use tkill () system call (or) pthread_kill library to raise a signal to consumer thread.
	pthread_kill(c_thread,SIGUSR2);
}
//Consumer Thread Implementation:
void *consumer(void *arg)
{
	//Step 1: Initialize consumer signal handler.
		(void) signal (SIGUSR2,cons_sig);
	//Step 2: Consumer raise a signal to producer thread.Use tkill () system call (or) pthread_kill library to raise a signal to producer thread.
		pthread_kill(p_thread,SIGUSR1);
	//Step 3: Waiting for a signal from producer thread inside infinite loop.Use pause () system call wait for a signal from producer thread.
		while(1){
			pause();
		}
}
//Consumer Signal Handler Implementation:
void cons_sig(int sig)
{
	//Step 1: Whenever signal received from producer thread, start read the buffer until buffer is empty.Use while () loop read Buffer until Buffer is EMPTY.
	int out = 0,n=26;
	char data[BUFSIZ +1];
	while(n)
	{
		data[out] = buffer[out];
		out = (out+1)% 26;
		if (out == 0)
			printf ("\t:c:%s\n",data); 
		n--;
	}
	//Step 2: Whenever the buffer is EMPTY, Consumer raise a signal to producer thread.Use tkill () system call (or) pthread_kill library to raise a signal to producer thread.
	pthread_kill(p_thread,SIGUSR1);
}
