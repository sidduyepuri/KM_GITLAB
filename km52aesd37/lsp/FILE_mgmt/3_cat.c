//3.Write a system programming your own version of cat command?
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
	int fd,ret,i;
	for(i=1;i<argc;i++)
	{
		fd=open(argv[i],O_RDONLY);
		while(1)
		{
			ret=read(fd,&ch,1);
			if(ret==0)
				break;
			write(1,&ch,1);
		}
		close(fd);
	}
	return 0;
}
