#include"dates.h"
int main()
{
	int n,d1,m1,y1,d2,m2,y2;
	printf("Number of candidates:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("Date of birth of candidate#%d:",i);
		scanf("%d-%d-%d",&d1,&m1,&y1);
		while(!(IsValidDate(d1,m1,y1)))
		{
			printf("Date is invalid, plz enter valid date:");	
			scanf("%d-%d-%d",&d1,&m1,&y1);
		}
		if(i>=2&&(Datecompare(d1,m1,y1,d2,m2,y2)==1))
			d2=d1,m2=m1,y2=y1;
		else if(i>=2&&(Datecompare(d1,m1,y1,d2,m2,y2)==0))
			d2=d2,m2=m2,y2=y2;
		else
			d2=d1,m2=m1,y2=y1;
	}
	PrintDateinFormat(d2,m2,y2);
	return 0;
}
