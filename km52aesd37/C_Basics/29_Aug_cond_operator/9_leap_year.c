//check if an year is leap year or not.

#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	n%100!=0?n%4==0?printf("leap year\n"):printf("Not a leap year\n"):n%400==0?printf("leap year\n"):printf("Not a leap year\n");
	return 0;
}
