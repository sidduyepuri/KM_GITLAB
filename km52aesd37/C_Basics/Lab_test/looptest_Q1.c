//Read two numbers from the user ,and print the older date.
#include<stdio.h>
int main()
{
	int n,d1,m1,y1,d2,m2,y2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d%d%d",&d1,&m1,&y1,&d2,&m2,&y2);
		if(y1>y2)
			printf("%d-%d-%d \n",d2,m2,y2);
		else if(y1<y2)
			printf("%d-%d-%d \n",d1,m1,y1);
		else if(m1>m2)
			printf("%d-%d-%d \n",d2,m2,y2);
		else if(m1<m2)
			printf("%d-%d-%d \n",d1,m1,y1);
		else if(d1>d2)
			printf("%d-%d-%d \n",d2,m2,y2);
		else if(d1<d2)
			printf("%d-%d-%d \n",d1,m1,y1);
		else
			printf("%d-%d-%d \n",d2,m2,y2);
	}
	return 0;
}
