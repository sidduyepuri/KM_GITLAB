//10) Write a function to accept a year as input and return 1 if the year is a leap year, otherwise 0.
#include<stdio.h>
int Isleap(int y)
{
	if(y%100!=0&&y%4==0||y%400==0)
		return 1;
	else
		return 0;
}
int main()
{
	int y;
	scanf("%d",&y);
	if(Isleap(y)==1)
		printf("Leap year\n");
	else
		printf("Not an leap\n");
	return 0;
}
