//1. Write a program to Set, clear and toggle particular bit using bit wise operator?

#include<stdio.h>
int main()
{
	int x,p;
	printf("Enter x and p:");
	scanf("%d%d",&x,&p);
	printf("SET=%d\n",x|(0x1<<p));
	printf("CLEAR=%d\n",x&(~(0x1<<p)));
	printf("TOGGLE=%d\n",x^(0x1<<p));
	return 0;

}
