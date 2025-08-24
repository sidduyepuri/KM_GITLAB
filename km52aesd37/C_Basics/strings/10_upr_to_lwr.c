// void strlwr( char str[]);
// convert all upper case alphabets to lower case in the given string
#include<stdio.h>
void str_lwr(char str[]);
int main()
{
	char str[20];
	scanf("%s",str);
	str_lwr(str);
	return 0;
}
void str_lwr(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++){
		if(str[i]<='Z'&&str[i]>='A')
			printf("%c",str[i]+32);
		else
			printf("%c",str[i]);
	}
	printf("\n");	
}
