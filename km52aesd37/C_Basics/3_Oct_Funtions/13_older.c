//13) Write a function that takes 2 dates as inputs, and returns 1 if the first date is old, 2 if the second date is old.
#include<stdio.h>
int older(int d1,int m1,int y1,int d2,int m2,int y2)
{
	if(y1>y2)
		return 2;
	else if(y1<y2)
		return 1;
	else if(m1>m2)
		return 2;
	else if(m1<m2)
		return 1;
	else if(d1>d2)
		return 2;
	else
		return 1;
}
int main()
{
	int d1,m1,y1,d2,m2,y2;
	scanf("%d%d%d%d%d%d",&d1,&m1,&y1,&d2,&m2,&y2);
	printf("%d is older\n",older(d1,m1,y1,d2,m2,y2));
	return 0;
}
