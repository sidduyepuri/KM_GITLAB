#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#define header_error(open) do { perror(open); exit(0); } while(1);
int main(int argc,char *argv[])
{
	int ret,len,i;
	int fd1,fd2;
	unsigned char *file1=NULL,*file2=NULL,*tmp;
	struct stat buf;
	if(argc!=3)
	{
		printf("Usage:$%s <source> <destination>\n",argv[0]);
		return 0;
	}
	fd1=open(argv[1],O_RDWR);
	if(fd1==-1)
		header_error("open");
	fd2=open(argv[2],O_RDWR);
	if(fd1==-1)
		header_error("open");
	if(fstat(fd1,&buf)==-1)
		header_error("fstat");
	len=buf.st_size;
	printf("size %d\n",len);
	file1 = (char *)mmap((void *)0,len,PROT_READ|PROT_WRITE, MAP_SHARED,fd1,0);
	if(file1==NULL)
		header_error("mmap");
	file2 = (char *)mmap((void *)0,len,PROT_READ|PROT_WRITE, MAP_SHARED,fd2,0);
	if(file2==NULL)
		header_error("mmap");
	tmp=file1;
	printf("addr1:%p\n",file1);
	printf("addr2:%p\n",file2);
	getchar();
	for(i=0;i<len;i++,file1++,file2++)
	{

		*file2=*file1;
		if(islower(*file1)){
			*file1=(char)(*file1-32);

		}
		printf(" %c \n",*file1);

	}
	getchar();
	i=munmap(tmp,len);
	if(i!=0)
		printf("failed to unmap\n");
	else
		printf("unmap success\n");
	return 0;

}
