// C program to check whether a number is odd or even using switch statement

#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d",&n);
	m=(n%2==0);
	switch(m)
	{
		case 1: printf("even number\n" );
			break;
		case 0: printf("Odd number\n");
			break;
		default: printf("Invalid\n");
	}
	return 0;
}
