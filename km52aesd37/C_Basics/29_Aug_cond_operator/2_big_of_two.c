//Write a program to find the biggest of two numbers using conditional operator.

#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=a>b?a:b;
	printf("big=%d\n",c);
	return 0;
}
