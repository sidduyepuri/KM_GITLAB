#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *const ps_argv[] = {"ps","-eaf",0};

int main()
{
	int ret;

	printf("starting line\n");

	getchar();
	ret = execve("/bin/ps",ps_argv,NULL);
	if (ret < 0){
		perror("execve fails");
		exit(0);
	}	

	printf("last line\n");
	return 0;
}
