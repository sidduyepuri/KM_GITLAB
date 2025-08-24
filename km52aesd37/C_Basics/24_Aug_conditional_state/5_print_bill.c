//Read an integer as input, and print if the given number is even or odd.

#include<stdio.h>
int main()
{
	int n,bill;
	printf("Enter no of calls:");
	scanf("%d",&n);
	if(n<=100)
		bill=250;
	else
		bill=250+1.25*(n-100);
	printf("%d\n",bill);
	return 0;
}
