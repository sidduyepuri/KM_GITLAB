//4) Create a dynamic array of integers. Take input from user , sort the array and display the output.

#include<stdio.h>
#include<stdlib.h>
void sorting(int *,int);
int main()
{
	int n,i;
	scanf("%d",&n);
	int *arr=(int *)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	sorting(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void sorting(int *arr,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
