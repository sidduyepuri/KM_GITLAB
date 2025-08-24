//Write a program to read n numbers, and print if each number is divisible with 10 or not.

#include<stdio.h>
int main()
{
	int i=1,n;
	scanf("%d",&n);
	while(i<=n)
	{
		int num;
		scanf("%d",&num);
		if(num%10==0)
			printf("Divisible by 10\n");
		else
			printf("Not Divisible by 10\n");
		i++;
	}
}
