#include <stdio.h>
int main()
{
	char ch;
	FILE *fp;
	fp=fopen("str.txt","r");
	char str[100];
	if(fp==NULL)
		printf("File is not exist\n");
	else
	{
		fgets(str,5,fp);
		fputs(str,stdout);
		fclose(fp);
	}
	return 0;
}

