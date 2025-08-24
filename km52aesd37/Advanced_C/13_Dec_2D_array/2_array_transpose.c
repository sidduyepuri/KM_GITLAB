/*2	Write the following program :
	Declare a two dimensional array of elements and find and print its transpose.
	eg., if the matrix is :       1 3
	                              4 5
	                              7 8

	its transpose should be :     1 4 7
	                              3 5 8		*/
#include<stdio.h>
int main()
{
	int r,c,i,j;
	scanf("%d%d",&r,&c);
	int arr[r][c];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d\t",arr[j][i]);
		}
		printf("\n");
	}
	
}
