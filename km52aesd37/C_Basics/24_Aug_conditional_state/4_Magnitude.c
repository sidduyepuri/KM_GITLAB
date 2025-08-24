//Read an integer as input, and print if the given number is even or odd.

#include<stdio.h>
int main()
{
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	if(n>0)
		printf("%d\n",n);
	else
		printf("%d\n",-n);
	return 0;
}
