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
	char *fdmap1,*fdmap2,*temp1=NULL,*temp2=NULL,ch;

	fd1=open(argv[1],O_RDONLY);
	if(fd1<0)
	{
		perror("open1 fails");
		exit(0);
	}
	fd2=open(argv[2],O_RDWR|O_CREAT,0666);
	printf("fd2=%d\n",fd2);
	if(fd2<0)
	{
		perror("open2 fails");
		exit(0);
	}
	if(fstat(fd1,&buffer) == -1){
               perror("stat");
               exit(0);
        }
	printf("stat success %ld\n",buffer.st_size);
	getchar();
	if(ftruncate(fd2,buffer.st_size)<0)
               perror("ftrucate fail");
	fdmap1=(char *) mmap(0,buffer.st_size, PROT_READ,MAP_PRIVATE,fd1,0);
	fdmap2=(char *) mmap(0,buffer.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd2,0);
	temp1=fdmap1;
	temp2=fdmap2;
	getchar();
	for(i=0;i<=buffer.st_size;i++)
	{
		*fdmap2=*fdmap1;
		fdmap1++;
		fdmap2++;
	}
//	getchar();
	munmap(temp1,buffer.st_size);
	munmap(temp2,buffer.st_size);
	close(fd1);
	close(fd2);
	return 0;	


}

