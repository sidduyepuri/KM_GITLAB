//Write a program to print all odd numbers and even numbers between two given numbers. print odd numbers in one loop and even in another loop after that.
#include<stdio.h>
int main()
{
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	printf("Even numbers:\n");
	for(int i=n1;i<n2;i++)
	{
		if(i%2==0)
			printf("%d\n",i);
	}
	printf("Odd numbers:\n");
	for(int i=n1;i<n2;i++)
	{
		if(i%2!=0)
			printf("%d\n",i);
	}
	return 0;
}
