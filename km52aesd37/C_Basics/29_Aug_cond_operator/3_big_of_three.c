//Write a program to find the biggest of three numbers using conditional operator.

#include<stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d%d%d",&a,&b,&c);
	d=a>b?a>c?a:c:b>c?b:c;
	printf("big=%d\n",d);
	return 0;
}
