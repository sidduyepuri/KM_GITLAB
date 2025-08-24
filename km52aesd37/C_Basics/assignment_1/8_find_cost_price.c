#include<stdio.h>
int main()
{
	int n,sp,profit;
	float cp;
	scanf("%d%d%d",&n,&sp,&profit);
	cp=(sp-profit)/n;
	printf("cost price=%f\n",cp);
	return 0;
}
