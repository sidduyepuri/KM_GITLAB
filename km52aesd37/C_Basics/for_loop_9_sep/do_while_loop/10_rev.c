/*Write a program to input a number and find and print the reverse of the number.*/

#include<stdio.h>
int main()
{
	int n,rev=0;
	scanf("%d",&n);
	do
	{
		rev=rev*10+n%10;
		n/=10;
	}while(n>0);
	printf("reverse=%d\n",rev);
	return 0;

}
