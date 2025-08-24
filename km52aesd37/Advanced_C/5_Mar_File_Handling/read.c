#include <stdio.h>
int main()
{
	char ch;
	FILE *fp;
	fp=fopen("abc.txt","r");
	if(fp==NULL)
		printf("File is not exist\n");
	else
	{
		while(1)
		{
			ch=fgetc(fp);
			if(ch==EOF)
				break;
			fputc(ch,stdout);
		}
		fclose(fp);
	}
	return 0;
}

