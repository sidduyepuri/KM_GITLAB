//Read the data from the user and print if the given date is valid or not.

#include<stdio.h>
int main()
{
	int d,m,y,temp=1;
	scanf("%d-%d-%d",&d,&m,&y);
	if((y<2200 && y>=1900) && (m<=12 && m>=1) && (d<=31 && d>=1))
	{
		switch((y%100!=0 && y%4==0) || (y%400==0))
		{
			case 1: if(m==2)
					if(d>29)
					temp=0;
				else if(m==4||m==6||m==9||m==11){
					if(d>=31)
					temp=0;}
				else
					temp=1;	
				break;	
			case 0: if(m==2)
					if(d>28)
					temp=0;
				else if(m==4||m==6||m==9||m==11)
				{	if(d>=31)
					temp=0;
				}
				else
					temp=1;		
		}
		if(temp==0)
			printf("Invalid Date\n");
		else
			printf("Valid Date\n");
	}
	else
		printf("Invalid Date\n");
	return 0;
}
