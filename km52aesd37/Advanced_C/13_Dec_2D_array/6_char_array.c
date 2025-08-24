//6. Declare a two dimensional array of characters, read names from the user and print them back with each individual character format (%c) in a loop.

#include<stdio.h>
int main()
{
	int r,c,i,j;
	scanf("%d%d",&r,&c);
	char arr[r][c];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf(" %c",&arr[i][j]);
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
}
