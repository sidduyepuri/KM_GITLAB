//4) Write a function that takes two numbers a and b, and returns the quotient after dividing a with b.
#include<stdio.h>
int Quotient(int a,int b)
{
	return a/b;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("Quotient=%d\n",Quotient(a,b));
	return 0;
}
