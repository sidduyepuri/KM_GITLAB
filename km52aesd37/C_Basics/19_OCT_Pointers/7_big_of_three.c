//7 Write a program to find the biggest of three numbers using pointers that point to those numbers.
#include<stdio.h>
int main()
{
	int a,b,c;
	int *x=&a,*y=&b,*z=&c;
	scanf("%d%d%d",x,y,z);
	int big=*x;
	if(*y>big)
		big=*y;
	if(*z>big)
		big=*z;
	printf("Big=%d\n",big);
	return 0;
}
