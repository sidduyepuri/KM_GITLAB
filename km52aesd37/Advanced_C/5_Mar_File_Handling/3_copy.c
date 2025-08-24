#include <stdio.h>
int main()
{
	int x=0;
	char ch;
	FILE *fp1,*fp2;
	fp1=fopen("content.txt","w+");
	fp2=fopen("copied.txt","w+");
	if(fp1==NULL)
		printf("File is not exist\n");
	else
	{
		while(1)
		{
			scanf("%c",&ch);
			fputc(ch,fp1);
			if(ch == EOF)
				break;
		}
		rewind(fp1);
		while(1)
		{
			ch=fgetc(fp1);
			if(ch == EOF)
				break;
			fputc(ch,fp2);
		}
		fclose(fp1);
		fclose(fp2);
	}
	return 0;
}

