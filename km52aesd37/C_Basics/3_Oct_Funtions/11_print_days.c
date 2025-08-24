//11) Write a function to accept a month and year as input, and return the number of days in that month as output. print the number of days in main.
#include<stdio.h>
int no_of_days(int m,int y)
{
	if(m==4||m==6||m==9||m==11)
		return 30;
	else if(m==2){
		if(y%100!=0&&y%4==0||y%400==0)
			return 29;
		else
			return 28;
	}
	else
		return 31;
}
int main()
{
	int m,y;
	scanf("%d%d",&m,&y);
	printf("No of days in this month is=%d\n",no_of_days(m,y));
	return 0;
}
