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
	int fd1,fd2,i;
	struct stat buffer;
	char *fdmap1,*temp;
	if(stat(argv[1], &buffer) == -1){
               perror("stat");
               exit(EXIT_FAILURE);
        }
	fd1=open(argv[1],O_RDWR);
	if(fd1<0)
	{
		perror("open1 fails");
		exit(0);
	}
	fdmap1=mmap((void *)0,buffer.st_size,PROT_WRITE|PROT_READ,MAP_SHARED,fd1,0);
	if(fdmap1==NULL)
	{
		perror("mmap");
		exit(0);
	}
	temp=fdmap1;
	for(i=0;i<buffer.st_size;i++,fdmap1++)
	{
		printf("%c",*fdmap1);
	}
	munmap(temp,buffer.st_size);
	return 0;	


}

