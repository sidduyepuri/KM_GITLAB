#include <stdio.h>
int main()
{
	int pos,fd;
	char ch;
	printf("Input number:");
	scanf("%d",&pos);
	FILE *fp=fopen("file.txt","r");
	if(fp==NULL)
		printf("File not exist\n");
	else
	{
		if(pos>0)
			fseek(fp,pos,SEEK_SET);
		else
			fd=fseek(fp,pos-1,SEEK_END);
		while(1)
		{
			ch=fgetc(fp);
			if(ch==EOF)
				break;
			printf("%c",ch);
		}
		fclose(fp);
	}
	return 0;
}

