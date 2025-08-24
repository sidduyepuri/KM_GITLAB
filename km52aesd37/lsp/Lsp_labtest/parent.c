#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void mywait(void);
int main()
{
	mywait();
	return 0;
}
void mywait(void)
{
	char ch;
	int data;
	int fd;
	while(1)
	{
		fd=open("abc",O_RDONLY);
		data=read(fd,&ch,1);
		if(ch=='1')
			break;
		write(1,&ch,1);
		close(fd);
	}
}
