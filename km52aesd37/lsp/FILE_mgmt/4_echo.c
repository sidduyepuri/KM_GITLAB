//4.Write a system programming your own version of echo command \?
#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	char ch;
	int i,len;
	char *buff;
	for(i=1;i<argc;i++)
	{
		buff=argv[i];
		len=strlen(buff);
		write(1,buff,len);
		write(1," ",1);
	}
	write(1,"\n",2);
	return 0;
}
