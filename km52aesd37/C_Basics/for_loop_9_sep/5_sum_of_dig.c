/*Write a program to input a number and print the sum of the digits of the number.
	Eg., 
	0 - sum of the digits 0
	12 - sum of the digits 3
	155 - sum of the digits 11 */
#include<stdio.h>
int main()
{
	int n,sum=0,temp=0;
	scanf("%d",&n);
	for(;n>0;)
	{
		temp=n%10;
		sum+=temp;
		n/=10;
	}
	printf("Sum of digits %d\n",sum);
}
