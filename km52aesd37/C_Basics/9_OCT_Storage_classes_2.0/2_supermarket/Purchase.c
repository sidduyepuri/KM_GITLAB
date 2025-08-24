#include<stdio.h>
int addstock(int);
extern int stock;
extern int items;
int purchas;
int p;
int purchase()
{
	int limit=1000;
	printf("Enter purchase stock:");
	scanf("%d",&items);
	if((stock+items)<=limit){
		addstock(items);
		purchas+=items;
		p++;
	}
	else
		printf("stock is exceeded, Enter stock upto %d\n",limit-stock);
}
