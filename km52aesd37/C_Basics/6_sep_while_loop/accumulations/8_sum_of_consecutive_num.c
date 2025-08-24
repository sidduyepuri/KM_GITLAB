//Find the sum of first n consecutive numbers starting from 1. n will be given as input.
#include<stdio.h>
int main()
{
	int i=1,n,sum=0;
	scanf("%d",&n);
	while(i<=n)
	{
		sum+=i;
		i++;
	}
	printf("sum=%d\n",sum);
	return 0;
}
