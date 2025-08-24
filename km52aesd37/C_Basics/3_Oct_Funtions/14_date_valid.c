//14) Write a  function that takes a date as input, and returns 1 if the date is valid, 0 if the date is invalid.
#include<stdio.h>
int Isvalid(int d,int m,int y)
{
	if((m==4||m==6||m==9||m==11)&&(d<=30&&d>=1))
			return 1;
	else if(m==2)
	{
		if((y%100!=0&&y%4==0||y%400==0)&&(d<=29&&d>=1))
			return 1;
		else if(d<=28&&d>=1)
			return 1;
	}	
	else if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d<=31&&d>=1))
			return 1;
	else
		return 0;
}
int main()
{
	int d,m,y;
	scanf("%d%d%d",&d,&m,&y);
	if(Isvalid(d,m,y)==1)
		printf("Date is valid\n");
	else
		printf("Not a valid\n");
	return 0;
}
