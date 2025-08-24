//4) Write a function that takes two numbers a and b, and returns the remainder after dividing a with b.
#include<stdio.h>
int Remainder(int a,int b)
{
	return a%b;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("Remainder=%d\n",Remainder(a,b));
	return 0;
}
