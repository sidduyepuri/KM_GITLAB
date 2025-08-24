//Write a program to find the power of a given number raised to the given exponent.
#include<stdio.h>
int main()
{
	int i=1,m,n,power=1;
	scanf("%d%d",&m,&n);
	while(i<=n)
	{
		power*=m;
		i++;
	}
	printf("power=%d\n",power);
	return 0;
}
