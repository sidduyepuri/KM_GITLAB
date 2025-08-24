/*1. Declare a two-dimensional array of elements for sales details of a store, for each item, for each salesman. Take the sales values as input and print the array in matrix form.
	Find out and print the following :
	1) Total sales by each sales man
	2) Total sales for a item
	3) Total sales			*/

#include<stdio.h>
int main()
{
	int salesman,items,i,j,sales=0,total=0,item=0;
	scanf("%d%d",&salesman,&items);
	int arr[salesman][items];
	for(i=0;i<salesman;i++)
	{
		for(j=0;j<items;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<salesman;i++)
	{
		for(j=0;j<items;j++)
		{
			sales+=arr[i][j];
			item+=arr[j][i];
		}
		total+=sales;
		printf("sales man %d total sales:%d,item %d sales:%d\n",i+1,sales,i+1,item);
		sales=0;
		item=0;
	}
	printf("Total sales:%d\n",total);
	

}
