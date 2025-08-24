//3. Write a program  for matrix addition and subtraction.

#include<stdio.h>
int main()
{
	int r,c,i,j;
	scanf("%d%d",&r,&c);
	int arr[r][c],arr1[r][c],res[r][c];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr1[i][j]);
		}
	}
	printf("Addition matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			res[i][j]=arr[i][j]+arr1[i][j];
			printf("%d  ",res[i][j]);
		}
		printf("\n");
	}
	printf("Subtraction matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			res[i][j]=arr[i][j]-arr1[i][j];
			printf("%d  ",res[i][j]);
		}
		printf("\n");
	}
}
