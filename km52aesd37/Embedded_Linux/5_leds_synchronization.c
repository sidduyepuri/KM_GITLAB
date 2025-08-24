#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <pthread.h>
#include <semaphore.h>
pthread_t red,green;
sem_t red1,green1;
int fd,fd1,fd3,fd4,a,b,l,ret,green_led_flag;
void *red_led(void *arg);
void *green_led(void *arg);
int main()
{
	struct input_event v;

	sem_init(&green1,0,0);

	fd=open("/sys/class/gpio/export",O_WRONLY);
	if(fd<0)
		perror("open1 fail");
	write(fd,"10",2);
	close(fd);

	fd=open("/sys/class/gpio/gpio10/direction",O_WRONLY);
	if(fd<0)
		perror("open2 fail");
	write(fd,"out",3);
	close(fd);
	fd=open("/sys/class/gpio/gpio10/value",O_WRONLY);
	if(fd<0)
		perror("open2 fail");

	fd1=open("/dev/input/event0",O_RDWR);
	if(fd1<0)
		perror("open3 fail");

	fd3=open("/sys/class/gpio/export",O_WRONLY);
	if(fd<0)
		perror("open4 fail");
	write(fd3,"9",1);
	close(fd3);

	fd3=open("/sys/class/gpio/gpio9/direction",O_WRONLY);
	if(fd<0)
		perror("open5 fail");
	write(fd3,"out",3);
	close(fd3);
	fd3=open("/sys/class/gpio/gpio9/value",O_WRONLY);
	if(fd3<0)
		perror("open6 fail");
	ret=pthread_create(&red,NULL,red_led,NULL);
	if(ret<0)
	{
		perror("pthread_create fail");
	}

	ret=pthread_create(&green,NULL,green_led,NULL);
	if(ret<0)
	{
		perror("pthread_create fail");
	}
	while(1)
	{

		read(fd1,&v,sizeof(v));
		if((v.code)==115 && v.value==1)
		{
			printf("before sem_post\n");
			sem_post(&green1);
			printf("after sem_post\n");
		}
	}
	close(fd);
	close(fd1);
	close(fd3);
	fd=open("/sys/class/gpio/unexport",O_WRONLY);
	if(fd<0)
		perror("open4 fail");
	write(fd,"10",5);
	close(fd);

	fd3=open("/sys/class/gpio/unexport",O_WRONLY);
	if(fd3<0)
		perror("open4 fail");
	write(fd3,"9",5);
	close(fd3);
	return 0;
}


void *red_led(void *arg)
{

	while(1)
	{

		write(fd,"1",1);
		sleep(1);
		write(fd,"0",1);
		sleep(1);
	}

}
void *green_led(void *arg)
{
	while(1)
	{
		sem_wait(&green1);
		write(fd3,"1",1);
		sleep(1);
		write(fd3,"0",1);
		printf("inside sem_init\n");
	}

}
