/*
   Write a system program to
   whenever UP Switch (GPIO0_26) Press blink GREEN LED(GPIO0_9) otherwise
   always Blink RED LED(GPIO0_10) every 1 sec Delay.

Hint:
- Create a two threads one is red_led thread and another one is green_led thread.
- red_led thread keep on blinking red led every 1 sec delay without any interruption.
- main thread keep on read UP switch event, whenever UP switch press set global flag (green_led_flag) is TRUE.
- green_led thread keep on checks global flag, whenever global flag is TRUE blink GREEN LED one iteration and immediately global flag set to FALSE (green_led_flag=0).

 */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/input.h>
#include <pthread.h>

void *redthread(void *arg);
void *greenthread(void *arg);

int green_flag = 0;
int fd1, fd2, fd3, ret, res;

int main()
{

	struct input_event ev;

	pthread_t a_thread,b_thread;
	void *thread_result;


	res = pthread_create(&a_thread, NULL, redthread, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&b_thread, NULL, greenthread, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Wait for pthread_join\n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_join(b_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined\n");

	while(1)
	{
		fd1 = open("/dev/input/event0", O_RDWR);
		if (fd1 == -1) {
			perror("Failed to open input device file");
			exit(EXIT_FAILURE);
		}

		ret = read(fd1, &ev, sizeof(struct input_event));
		if (ret == -1) {
			perror("Failed to read from input device file");
			close(fd1);
			exit(EXIT_FAILURE);
		}

		if (ev.code == 114 && ev.value == 0)
		{
			fd3 = open("/sys/class/gpio/gpio10/value", O_WRONLY);
			if (fd3 == -1) {
				perror("Failed to open value file");
				close(fd1);
				exit(EXIT_FAILURE);
			}
			ret = write(fd3, "0", 1);
			if (ret == -1) {
				perror("Failed to write to value file");
				close(fd3);
				close(fd1);
				exit(EXIT_FAILURE);
			}
			close(fd3);
		}

	}

	fd4 = open("/sys/class/gpio/unexport", O_WRONLY);
	if (fd4 < 0) {
		perror("open4 fail:");
		return 1;
	}

	ret = write(fd4, "10", 2); 
	if (ret < 0) {
		perror("write4 fail:");
		close(fd4);
		return 1;
	}

	close(fd4); 		

	return 0;
}

void *redthread(void *arg)
{
	int fd1, fd2, fd3, fd4, ret;
	fd1 = open("/sys/class/gpio/export", O_WRONLY);
	if (fd1 < 0) {
		perror("open1 fail:");
		return 1;
	}

	ret = write(fd1, "10", 2); 
	if (ret < 0) {
		perror("write1 fail:");
		close(fd1);
		return 1;
	}

	close(fd1); 

	fd2 = open("/sys/class/gpio/gpio10/direction", O_WRONLY);
	if (fd2 < 0) {
		perror("open2 fail:");
		return 1;
	}

	ret = write(fd2, "out", 3); 
	if (ret < 0) {
		perror("write2 fail:");
		close(fd2);
		return 1;
	}

	close(fd2); 

	fd3 = open("/sys/class/gpio/gpio10/value", O_WRONLY);
	if (fd3 < 0) {
		perror("open3 fail:");
		return 1;
	}

	int i;
	for (i = 0; i < 25; i++) {
		ret = write(fd3, "1", 1); 
		if (ret < 0) {
			perror("write3 fail:");
			close(fd3);
			return 1;
		}
		sleep(1);

		ret = write(fd3, "0", 1); 
		if (ret < 0) {
			perror("write3 fail:");
			close(fd3);
			return 1;
		}
		sleep(1);
	}

	close(fd3); 

	fd4 = open("/sys/class/gpio/unexport", O_WRONLY);
	if (fd4 < 0) {
		perror("open4 fail:");
		return 1;
	}

	ret = write(fd4, "10", 2); 
	if (ret < 0) {
		perror("write4 fail:");
		close(fd4);
		return 1;
	}

	close(fd4); 


}

void *greenthread(void *arg)
{

}
