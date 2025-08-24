//3) Write a function that takes two numbers a and b as input arguments and returns their product as return value , without using * operator
#include<stdio.h>
int mul(int a,int b)
{
	int prod;
	for(int i=1;i<=b;i++)
		prod+=a;
	return prod;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("Multiplication=%d\n",mul(a,b));
	return 0;
}
