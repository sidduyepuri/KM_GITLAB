#include <stdio.h>
int main()
{
	int x=0;
	char ch;
	FILE *fp1,*fp2,*fp3;
	fp1=fopen("file1.txt","r");
	fp2=fopen("file2.txt","a+");
	fp3=fopen("file3.txt","w+");
	if(fp1==NULL)
		printf("File is not exist\n");
	else
	{
		while(1)
		{
			ch=fgetc(fp1);
			if(ch == EOF)
				break;
			fputc(ch,fp2);
			printf("%c",ch);
		}
		rewind(fp2);
		while(1)
		{
			ch=fgetc(fp2);
			if(ch == EOF)
				break;
			fputc(ch,fp3);
		}
		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
	}
	return 0;
}

