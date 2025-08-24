//Write a calculator program that takes two integer numbers from user, and one of the operands +,-,* and / as a character and prints the appropriate result using if else.

#include<stdio.h>
int main()
{
	int a,b;
	char ch;
	scanf("%d %c%d",&a,&ch,&b);
	if(ch=='+')
		printf("%d+%d=%d\n",a,b,a+b);
	else if(ch=='-')
		printf("%d-%d=%d\n",a,b,a-b);
	else if(ch=='*')
		printf("%d*%d=%d\n",a,b,a*b);
	else if(ch=='/')
		printf("%d/%d=%d\n",a,b,a/b);
	else if(ch=='%')
		printf("%d%%%d=%d\n",a,b,a%b);
	else
		printf("Entered wrong key operator\n");
	return 0;
}
