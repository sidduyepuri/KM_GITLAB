//8.Write a system programming your own version of touch command?
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	char ch;
	int fd,fd2,ret,i;
	for(i=1;i<argc;i++)
	{
		fd=open(argv[i],O_CREAT,0666);
		close(fd);
	}
	return 0;
}
