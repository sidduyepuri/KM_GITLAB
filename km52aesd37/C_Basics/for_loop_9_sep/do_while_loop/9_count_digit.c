/*Write a program to input a number and count the digits in it.
	Eg.
	0 - number of digits 1
	12 – number of digits 2
	155 – number of digits 3	*/
#include<stdio.h>
int main()
{
	int n,count=0;
	scanf("%d",&n);
	do
	{
		n/=10;
		count++;
	}while(n>0);
	printf("count=%d\n",count);
	return 0;

}
