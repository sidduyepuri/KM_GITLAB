//12 Write a function to modify the array such that all negative numbers are converted to positive.
#include<stdio.h>
void negative_num(int arr[],int);
int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	negative_num(arr,n);
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}
void negative_num(int arr[],int n)
{
	int i,temp;
	for(i=0;i<n;i++)
		if(arr[i]<0)
			arr[i]=-arr[i];
}
