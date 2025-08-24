//9) char * strchr( char s[], char c); // returns address of given character first occurrence in given string

#include<stdio.h>
char *str_chr(char str[],char ch);
int main()
{
	char str[10],ch;
	printf("Enter string:");
	scanf("%s",str);
	printf("Enter character for searching:");
	scanf(" %c",&ch);
	char *i=str_chr(str,ch);
	printf("starting address=%p\n",str);
	printf("Address of character %p\n",i);
	return 0;
}
char *str_chr(char *str,char ch)
{
	for(;*str!='\0';)
	{
		if(*(str)==ch){
			break;
		}
		str++;
	}
	return str;
}

