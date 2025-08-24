//11) void strupr (char str[]);
// convert all lower case alphabets to upper case in the given string
#include<stdio.h>
void str_upr(char str[]);
int main()
{
	char str[20];
	scanf("%s",str);
	str_upr(str);
	return 0;
}
void str_upr(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++){
		if(str[i]<='z'&&str[i]>='a')
			printf("%c",str[i]-32);
		else
			printf("%c",str[i]);
	}
	printf("\n");	
}
