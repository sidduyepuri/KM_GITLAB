//Read n dates from user and print the oldest date of all.
#include<stdio.h>
int main()
{
	int i=1,n,d,m,y;
	scanf("%d",&n);
	scanf("%d%d%d",&d,&m,&y);
	while(i<n)
	{
		int d1,y1,m1;
		scanf("%d%d%d",&d1,&m1,&y1);
		if(y1<y)
			d=d1,m=m1,y=y1;
		else if(y1==y && m1<m)
			d=d1,m=m1,y=y1;
		else if(y1==y && m1==m && d1<d)
			d=d1,m=m1,y=y1;
		i++;
	}
	printf("%d-%d-%d is older\n",d,m,y);
	return 0;
}
