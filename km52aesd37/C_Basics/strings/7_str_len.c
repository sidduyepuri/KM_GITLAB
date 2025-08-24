//7) int strlen( char str[]);
//returns the length of the string.
#include<stdio.h>
int str_len(char str[]);
int main()
{
	char str[30];
	scanf("%[^\n]s",str);
	int len=str_len(str);
	printf("Length=%d\n",len);
	return 0;
}
int str_len(char str[])
{
	int i,len=0;
	for(i=0;str[i]!='\0';i++)
		len++;
	return len;
}
