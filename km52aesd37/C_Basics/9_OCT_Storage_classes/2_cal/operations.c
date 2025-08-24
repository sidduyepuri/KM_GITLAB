#include<stdio.h>
extern int a,b;
extern char ch;
int c;
void fun()
{
	switch(ch)
	{
		case '+': c=a+b; break;
		case '-': c=a-b; break;
		case '*': c=a*b; break;
		case '/': c=a/b; break;
		case '%': c=a%b; break;	
		default: printf("Invalid operator\n");
	}
}
