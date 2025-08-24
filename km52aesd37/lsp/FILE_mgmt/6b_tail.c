//6.Write a system programming your own version of tail command?
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int count_lines(int ,char *argv[]);
void print_lines(int,int,int,char *argv[]);
int main(int argc,char *argv[])
{
	char ch;
	int j,i,fd,ret,l=1,count=0,n,k=0,p;
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
		count=count_lines(j,argv);
		print_lines(j,count,n,argv);
	}
	close(fd);
	return 0;
}
int count_lines(int j,char *argv[])
{
	int fd=open(argv[j],O_RDONLY);
	char ch;
	int count=0,ret;
	while(1)
	{
		ret=read(fd,&ch,1);
		if(ret==0)
			break;
		if(ch=='\n')
			count++;
	}
	return count;
}
void print_lines(int j,int count,int n,char *argv[])
{
	int fd=open(argv[j],O_RDONLY);
	printf("==> %s <==\n",argv[j]);
	char ch;
	int p=count-n,ret,i;
	for(i=1;i<=count;)
	{

			if(i>p)
			{

				while(1)
				{
					read(fd,&ch,1);
					if(ch=='\n')
					{
						write(1,"\n",2);
						i++;
						break;
					}
					write(1,&ch,1);
				}
			}
			else
			{
				ret=read(fd,&ch,1);
				if(ch=='\n')
				{
					i++;
				}
			}
	}
}
