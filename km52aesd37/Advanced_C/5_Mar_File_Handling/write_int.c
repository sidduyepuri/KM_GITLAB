#include <stdio.h>
int main()
{
	char ch;
	FILE *fp;
	fp=fopen("file.txt","w");
	if(fp==NULL)
		printf("File is not exist\n");
	else
	{
		while(1)
		{
			ch=getchar();
			if(ch==EOF)
				break;
			putw(ch,fp);
		}
		fclose(fp);
	}
	return 0;
}

