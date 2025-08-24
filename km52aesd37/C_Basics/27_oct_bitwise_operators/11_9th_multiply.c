//11. WAP multiply a number by 9 using bit shift.

#include<stdio.h>
int main()
{
	int x;
	printf("Enter x:");
	scanf("%d",&x);
	printf("9 x %d = %d\n",x,(x<<3)+x);
	return 0;
}
