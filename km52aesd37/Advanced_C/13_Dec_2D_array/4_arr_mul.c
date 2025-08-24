//4.Write a program  for matrix multiplication.
#include<stdio.h>
int main()
{
	int r,c,i,j,k,sum=0;
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
	printf("Multiplication matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			for(k=0;k<r;k++)
			{
				sum+=arr[i][k]*arr1[k][j];
			}
			res[i][j]=sum;
			printf("%d  ",res[i][j]);
			sum=0;
		}
		printf("\n");
	}
}
