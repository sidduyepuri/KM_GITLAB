//5.Write a system programming your own version of cp command?
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int args,char *argv[])
{
	char ch;
	int fd,fd2,ret,i;
	fd=open(argv[1],O_RDONLY);
	fd2=open(argv[2],O_RDWR);
	if(fd2<0)
	{
		fd2=open(argv[2],O_CREAT,0666);
		printf("fd2=%d\n",fd2);
	}
	if(fd < 0)
	{
		perror("open file");
		exit(0);
	}
	while(1)
	{
		ret=read(fd,&ch,1);
		if(ret==0)
			break;
		i=write(fd2,&ch,1);
		if(i<0){
			perror("write file");
			exit(0);
		}
	}
	close(fd);
	close(fd2);
	return 0;
}
