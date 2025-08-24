#include<stdio.h>
int addstock(int);
extern int stock;
extern int items;
int purchase()
{
	int limit=1000;
	printf("Enter purchase stock:");
	scanf("%d",&items);
	if((stock+items)<=limit){
		addstock(items);
	}
	else
		printf("stock is exceeded, Enter stock upto %d\n",limit-stock);
}
