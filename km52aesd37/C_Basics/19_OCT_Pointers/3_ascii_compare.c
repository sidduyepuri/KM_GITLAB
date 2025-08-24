//3 Write a program to take input for two character variables using pointers and find out which character has higher ascii value.
#include<stdio.h>
int main()
{
	char c,d;
	char *p=&c,*q=&d;
	scanf("%c %c",p,q);
	if(*p>*q)
		printf("%c is higher ascii value\n",*p);
	else
		printf("%c is higher ascii value\n",*q);
	return 0;
}
