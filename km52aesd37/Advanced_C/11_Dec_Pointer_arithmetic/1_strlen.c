// 1) int strlen(char s[]);

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
int str_len(char *str)
{
	int i=0;
	for(;*(str+i)!='\0';i++);
	return i;
}

