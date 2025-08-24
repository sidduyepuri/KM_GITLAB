//Repeat the date comparison program for n times. Read 2 dates n times, every time print which date is old.
#include<stdio.h>
int main()
{
	int i=1,n;
	scanf("%d",&n);
	while(i<=n)
	{
		int d1,m1,y1,d2,m2,y2;
		scanf("%d%d%d%d%d%d",&d1,&m1,&y1,&d2,&m2,&y2);
		if(y1>y2)
			printf("%d-%d-%d is older",d2,m2,y2);
		else if(y1<y2)
			printf("%d-%d-%d is older",d1,m1,y1);
		else if(m1>m2)
			printf("%d-%d-%d is older",d2,m2,y2);
		else if(m1<m2)
			printf("%d-%d-%d is older",d1,m1,y1);
		else if(d1>d2)
			printf("%d-%d-%d is older",d2,m2,y2);
		else if(d1>d2)
			printf("%d-%d-%d is older",d1,m1,y1);
		else
			printf("Both dates are same\n");
		i++;
	}
	return 0;
}
