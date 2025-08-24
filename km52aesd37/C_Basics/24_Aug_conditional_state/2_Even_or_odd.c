//Read an integer as input, and print if the given number is even or odd.

#include<stdio.h>
int main()
{
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	if(n%2==0)
		printf("%d is even number\n",n);
	else
		printf("%d is odd number\n",n);
	return 0;
}
