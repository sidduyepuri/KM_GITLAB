/*5	Search for an element in a two dimensional array, and print its position - as row and column numbers. write a search function that will receive the array and return row and column indexes as output. */

#include<stdio.h>

int i,j;
char *search_element(int,int,int,int arr[][4]);

int main()
{
	int r,c,val;
	char *res;
	scanf("%d%d",&r,&c);
	int arr[r][c];
	printf("Enter array elements:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Enter finding elements:");
	scanf("%d",&val);
	res=search_element(r,c,val,arr);
	printf("Row=%d\ncolumn=%d\n",*res,*(res+1));
	return 0;
}
char *search_element(int r,int c,int find,int arr[r][c])
{
	char temp[10];
	char *ret=temp;
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(arr[i][j]==find){
				*ret=i;
				*(ret+1)=j;
				return ret;
			}
		}
	}
}
