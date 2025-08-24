//Write a system programming your own version of getchar() standard C Library?
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	char ch;
	int ret;
	ret=read(0,&ch,1);
	if(ret<0){
		perror("read call");
		exit(0);
	}
	write(1,&ch,1);
	write(1,"\n",1);
	return 0;
}
