//2) Write a function that takes two numbers, a and n as input arguments and returns the value of a to the power of n, without using * operator
#include"main2.h"
int main()
{
	int a,n,pow=0;
	scanf("%d%d",&a,&n);
	int temp=a;
	pow=power(a,n,temp);
	printf("Power=%d\n",pow);
	
}
