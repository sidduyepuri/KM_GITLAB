//Read n number of dates, and print each date belongs to leap year or not.
#include<stdio.h>
int main()
{
	int i=1,n;
	scanf("%d",&n);
	while(i<=n)
	{
		int d,m,y;
		scanf("%d-%d-%d",&d,&m,&y);
		if(y%100!=0 && y%4==0 || y%400==0)
			printf("Leap year\n");
		else
			printf("Not a leap\n");
		i++;
	}
	return 0;	
}
