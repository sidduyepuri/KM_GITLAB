//Write a program to find the product of two integers without using * operator.
#include<stdio.h>
int main()
{
	int i=1,m,n,prod=0;
	scanf("%d%d",&m,&n);
	while(i<=m)
	{
		prod+=n;
		i++;
	}
	printf("product=%d\n",prod);
	return 0;
}
