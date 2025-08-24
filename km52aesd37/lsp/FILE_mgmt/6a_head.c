//6.Write a system programming your own version of head command?
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
	int i,j,fd,ret,count,n;
	if(argc>=4)
	{
		n=atoi(argv[2]);
		j=3;
	}
	else{
		n=10;
		j=1;
	}
	for(;j<argc;j++)
	{
		fd=open(argv[j],O_RDONLY);
		if(argc>=3)
			printf("==> %s  <==\n",argv[j]);
		for(i=0;i<n;i++)
		{
			while(1)
			{
				ret=read(fd,&ch,1);
				if(ch=='\n')
				{
					break;
				}
				write(1,&ch,1);
			}
			if(i+1<n)
				write(1,&ch,1);
		}
		write(1,"\n",1);
	}
	close(fd);
	return 0;
}
