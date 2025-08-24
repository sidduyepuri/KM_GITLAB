//WAP your own version of system library.
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>
int mysystem(const char *str);
int main()
{
    char str[20];
    printf("start\n");
    scanf("%[^\n]s",str);
    mysystem(str);
    printf("end\n");
    exit(0);
}
int mysystem(const char *str)
{
	pid_t pid;
	int ret,status;
	pid = fork();
	if (pid == 0)
	{
		execl("/bin/sh", "sh", "-c", str, (char *) 0);	//ret = execl("/bin/ps",str,NULL);
		if(ret == -1)
		perror("execve fails");
		exit(0);
	}
	else
	{
		//printf("parent\n");
		wait(&status);
	}
}

