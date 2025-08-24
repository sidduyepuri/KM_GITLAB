//6 Write a function to search for a specific element given by the user, in an array and display its index.  Function takes array and element to search as inputs, and returns the index as output. If element not found, return -1.
#include<stdio.h>
int search(int arr[],int,int);
int main()
{
	int n,i,s;
	printf("Enter size of the array:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter number for searching:");
	scanf("%d",&s);
	i=search(arr,n,s);
	if(i==-1)
		printf("Not found\n");
	else
		printf("Number at index %d\n",i);
	return 0;
}

int search(int arr[],int n,int s)
{
	int i;
	for(i=0;i<n;i++)
		if(arr[i]==s)
			return i;
	return -1;
}
