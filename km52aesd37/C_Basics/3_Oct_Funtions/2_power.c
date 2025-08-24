//2) Write a function that takes two numbers, a and n as input arguments and returns the value of a to the power of n.
#include<stdio.h>
int power(int m,int n);
int multiply(int m,int n);
int temp=0;
int main()
{
	int m,n,pow=0;
	scanf("%d%d",&m,&n);
	temp=m;
	pow=power(m,n);
	printf("Power=%d\n",pow);
}
int power(int m,int n)
{
	int p=0;
	for(int i=1;i<n;i++){
		p+=multiply(m,n);
		temp=p;
		p=0;
	}
	return temp;
}
int multiply(int m,int n)
{
	int mul=0;
	for(int i=1;i<=m;i++){
		mul+=temp;
	}
	return mul;
}
