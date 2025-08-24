#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
	int ret,fd;
	fd=open("/sys/class/gpio/export",O_WRONLY);
	if(fd<0)
	{
		perror("open 1 fail");
		exit(0);
	}
	ret=write(fd,"10",2);
	if(ret<0)
	{
		perror("write fails");	
		exit(0);
	}
	close(fd);

	fd=open("/sys/class/gpio/gpio10/direction",O_WRONLY);
	if(fd<0)
	{
		perror("open 2 fails");
		exit(0);
	}
	ret=write(fd,"out",3);
	if(ret<0)
	{
		perror("write fails");
		exit(0);
	}
	close(fd);
	while(1)
	{
		fd=open("/sys/class/gpio/gpio10/value",O_WRONLY);
		if(fd<0)
		{
			perror("open 3 fails");
			exit(0);
		}
		ret=write(fd,"1",1);
		if(ret<0)
		{
			perror("write fails");
			exit(0);
		}
		sleep(1);
		close(fd);	
		fd=open("/sys/class/gpio/gpio10/value",O_WRONLY);
		if(fd<0)
		{
			perror("open 4 fails");
			exit(0);
		}
		ret=write(fd,"0",1);
		if(ret<0)
		{
			perror("write fails");
			exit(0);
		}
		sleep(1);
		close(fd);
	}
	fd=open("/sys/class/gpio/unexport",O_WRONLY);
	if(fd<0)
	{
		perror("open 5 fails");
		exit(0);
	}
	ret=write(fd,"10",2);
	if(ret<0)
	{
		perror("write fails");
		exit(0);
	}
	close(fd);
	exit(0);
}
