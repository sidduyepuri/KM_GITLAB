#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void myexit(void);
int main()
{
	myexit();
	return 0;
}
void myexit(void)
{
	int buff;
	int ret;
	int fd=open("abc",O_RDWR);
	if(fd<0)
		perror("open Fails");
	ret=read(0,&buff,1);
	if(ret<0)
		perror("read Fails");
	write(fd,&buff,1);
}
