//Write a program that reads a file containing integers and appends the sum of all integers at the end.
#include <stdio.h>
int main()
{
	int x=0,sum=0;
	FILE *fp;
	fp=fopen("file1.txt","a+");
	if(fp==NULL)
		printf("File is not exist\n");
	else
	{
		while((x=getw(fp))!=EOF)
		{
			sum+=x;
		}
		putw(sum,fp);
		rewind(fp);
		while((x=getw(fp))!=EOF)
		{
			printf("%d\n",x);
		}
		fclose(fp);
	}
	return 0;

}
