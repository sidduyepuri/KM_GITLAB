// Write a program to find out if an integer entered by a user is a prime number or not. Count the factors of the given number to identify prime number.
#include<stdio.h>
int main()
{
	int n,count=0;
	scanf("%d",&n);
	for(int i=2;i<=n/2;i++)
	{
		if(n%i==0){
			count++;
			break;
		}
	}
	if(count==0)
		printf("it is a Prime\n");
	printf("count=%d\n",count);
}
