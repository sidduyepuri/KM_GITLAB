//WAP to create your own version of shell.
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>
int mysystem(const char *command);
int main()
{
	char command[20];
	printf("start\n");
	while(1){
		printf("$ ");
		scanf(" %[^\n]s",command);
		if(strcmp(command,"exit")==0)
			break;
		mysystem(command);
	}	
	exit(0);
}
int mysystem(const char *command)
{
	pid_t pid;
	int ret,status;
	pid = fork();
	if (pid == 0)
	{
		ret=execl("/bin/sh", "sh", "-c", command, (char *) 0);	//ret = execl("/bin/ps",str,NULL);
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

