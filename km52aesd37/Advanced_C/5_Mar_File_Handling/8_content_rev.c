#include <stdio.h>
#include <string.h>
void str_rev(char *str);
int main()
{
	int i=0;
	char ch,str2[100];
	FILE *fp;
	fp=fopen("text.txt","w+");
	if(fp==NULL)
		printf("File not exist\n");	
	else
	{
		while(1)
		{
			ch=getc(stdin);
			if(ch==EOF)
				break;
			fputc(ch,fp);
		}
		rewind(fp);
		fgets(str2,sizeof(str2),fp);
		fclose(fp);
		str_rev(str2);
		printf("%s\n",str2);
	}
}
void str_rev(char *str)
{
	int i,j=strlen(str)-1;
	char temp;
	for(i=0;i<j;i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}

}
