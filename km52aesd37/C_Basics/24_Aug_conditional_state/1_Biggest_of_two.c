/*Write a program to read 2 numbers and print the biggest of the two numbers.
	eg., 
	enter 2 numbers: 10  15
	output: 15 is the biggest of given numbers */
#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter 2 numbers:");
	scanf("%d%d",&a,&b);
	if(a>b)
		printf("%d is biggest number\n",a);
	else
		printf("%d is biggest number\n",b);
	return 0;
}
