/*5). "Write a program to convert a string into upper case and print.
eg., input : Hello
output : HELLO"		*/
#include<stdio.h>
int main()
{
	char str[10];
	scanf("%s",str);
	int i;
	for(i=0;str[i]!=0;i++)
		if(str[i]<='z'&&str[i]>='a')
			printf("%c",str[i]-32);
		else
			printf("%c",str[i]);

	printf("\n");
	return 0;
}
