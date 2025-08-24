//6) Write a function that takes an integer number as input and prints its multiplication table.return type is  void.
#include<stdio.h>
void mul(int n)
{
	for(int i=1;i<=10;i++)
	{
		printf("%d*%d=%d\n",n,i,n*i);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	mul(n);
	return 0;
}
