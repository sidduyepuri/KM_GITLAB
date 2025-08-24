//1) Write a program to swap two numbers using Call by Value and Call by Reference.
#include<stdio.h>
void swap(int *,int *);
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	swap(&x,&y);
	printf("x=%d\ny=%d\n",x,y);
	printf("&x=%p\n&y=%p\n",&x,&y);
	return 0;
}
void swap(int *p,int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
	printf("*p=%d\n*q=%d\n",*p,*q);
	printf("p=%p\np=%p\n",p,q);
}
