//check if a given year is leap year or not.

#include<stdio.h>
int main()
{
	int n;
	printf("Enter year:");
	scanf("%d",&n);
	if(n%100==0)
	{
		if(n%400==0)
			printf("%d is a leap year\n",n);
	}
	else if(n%100!=0)
	{
		if(n%4==0)
			printf("%d is a leap year\n",n);
	}
	else
			printf("%d is not a leap year\n",n);
	return 0;
}
