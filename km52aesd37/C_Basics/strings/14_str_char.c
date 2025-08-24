//14) int strchr( char str[], char ch)
// search the character ch ,in string str , whenever the first matching occurs, return the matching index.
#include<stdio.h>
int str_chr(char str[],char ch);
int main()
{
	char str[10],ch;
	printf("Enter string:");
	scanf("%s",str);
	printf("Enter character for searching:");
	scanf(" %c",&ch);
	int i=str_chr(str,ch);
	printf("The character found at index %d\n",i);
	return 0;
}
int str_chr(char str[],char ch)
{
	int i;
	for(i=0;str[i]!='\0';i++)
		if(str[i]==ch)
			break;
	return i;
}
