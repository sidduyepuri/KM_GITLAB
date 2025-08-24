//8.Write a system programming your own version of du command?
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
	int i,fd,ret,count=0,n,wc=0,lc=0,cc=0,total=0;
	fd=open(argv[3],O_RDWR);
	for(i=1;i<argc;i++)
	{
		fd=open(argv[i],O_RDWR);
		while(1)
		{
			ret=read(fd,&ch,1);
			if(ret==0)
				break;
			cc++;
		}
		total=cc/4096;
		if((cc%4096)<4096)
			total+=1;
		printf("%dK      %s\n",4*total,argv[i]);
	}	
	close(fd);
	return 0;
}
