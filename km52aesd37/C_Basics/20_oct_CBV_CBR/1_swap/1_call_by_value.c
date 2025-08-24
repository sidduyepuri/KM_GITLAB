//1) Write a program to swap two numbers using Call by Value and Call by Reference.
#include<stdio.h>
void swap(int,int);
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	swap(x,y);
	printf("x=%d\ny=%d\n",x,y);
	return 0;
}
void swap(int a,int b)
{
	int t;
	t=a;
	a=b;
	b=t;
	printf("a=%d\nb=%d\n",a,b);
}
