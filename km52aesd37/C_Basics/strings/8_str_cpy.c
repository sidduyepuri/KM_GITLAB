//8) void strcpy ( char d[] . char s[]);
//copies all characters from source string (char s[]) to destination string( char d[]) , upto null character ( including null character).
#include<stdio.h>
void str_cpy(char str1[],char str2[]);
int main()
{
	char str1[30],str2[30];
	scanf("%s",str2);
	str_cpy(str1,str2);
	printf("string1=%s\n",str1);
	return 0;
}
void str_cpy(char str1[],char str2[])
{
	int i;
	for(i=0;str2[i]!='\0';i++){
		str1[i]=str2[i];
	}
	str1[i]='\0';
}
