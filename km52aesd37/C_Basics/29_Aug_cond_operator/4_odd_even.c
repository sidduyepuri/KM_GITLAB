//Write a program that determines whether a given integer is odd or even and displays the appropriate message

#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	n%2==0?printf("%d is Even number\n",n):printf("%d is odd number\n",n);
	return 0;
}
