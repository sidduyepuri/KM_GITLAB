#include <stdio.h>
int main()
{
	char ch;
	FILE *fp;
	fp=fopen("str.txt","w+");
	char *str="Welcome to kernel masters\n";
	if(fp==NULL)
		printf("File is not exist\n");
	else
	{
		fputs(str, fp);
		fclose(fp);
	}
	return 0;
}

