#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int fd;
	fd=open(argv[1],O_RDWR);
	if(fd<0){
		perror("open fails");
		exit(0);
	}
	getchar();
	char *temp;
	unsigned char *ptr=mmap((void *)0,6,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(ptr==NULL){
		perror("mmap fails");
		exit(0);
	}
	int i=0;
	temp=ptr;
	getchar();
	for(;i<4;i++)
	{
		*ptr=(i+65);
		ptr++;
	}
	munmap(temp,6);
	return 0;
}

