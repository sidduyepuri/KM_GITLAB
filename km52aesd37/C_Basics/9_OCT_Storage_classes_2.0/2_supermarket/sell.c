#include<stdio.h>
int deletestock(int);
extern int stock;
int items;
int sales,s;
int sell()
{
	printf("Enter sell items:");
	scanf("%d",&items);
	if(stock>=items){
		deletestock(items);
		sales+=items;
		s++;
	}
	else
		printf("Stock is not enough please purchase\n");
}
