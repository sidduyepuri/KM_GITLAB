//2 Write a program to add two variables using their pointers.
#include<stdio.h>
int main()
{
	int x,y;
	int *p=&x,*q=&y;
	scanf("%d%d",p,q);
	printf("Addition=%d\n",*p+*q);
	return 0;
}
