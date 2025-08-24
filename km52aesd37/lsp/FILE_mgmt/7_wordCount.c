//7.Write a system programming your own version of wc command?
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
	char ch;
	int i,fd,ret,count=0,wc=0,lc=0,cc=0,lt=0,ct=0,wt=0;
	for(i=1;i<argc;i++)
	{
		fd=open(argv[i],O_RDWR);
		while(1)
		{
			ret=read(fd,&ch,1);
			if(ret==0)
				break;
			if(ch==' '||ch=='\n')
				wc++;
			if(ch=='\n')
				lc++;
			cc++;
		}
		lt+=lc,ct+=cc,wt+=wc;
		printf(" %d %d %d %s\n",lc,wc,cc,argv[i]);
		lc=0,cc=0,wc=0;
	}
	if(argc>2)
	{
		printf(" %d %d %d %s\n",lt,wt,ct,"total");
	}
	close(fd);
	return 0;
}
