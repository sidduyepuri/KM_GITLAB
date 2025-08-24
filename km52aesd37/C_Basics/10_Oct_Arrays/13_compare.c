//13) write a function to take 2 arrays as input and return 1 if they are equal and 0 if they are not equal ( sizes to be sent as seperate arguments)
#include<stdio.h>
int compare(int arr1[],int,int arr2[],int);
int main()
{
	int m,n,i;
	printf("Enter size of the array 1:");
	scanf("%d",&m);
	printf("Enter size of the array 2:");
	scanf("%d",&n);
	int arr1[m],arr2[n];
	printf("Enter values of array 1:");
	for(i=0;i<m;i++)
		scanf("%d",&arr1[i]);
	printf("Enter values of array 2:");
	for(i=0;i<n;i++)
		scanf("%d",&arr2[i]);
	i=compare(arr1,m,arr2,n);
	if(i==1)
		printf("Both arrays are equal\n");
	else
		printf("Not equal\n");
}
int compare(int arr1[],int m,int arr2[],int n)
{
	int i;
	if(m==n)
	{
		for(i=0;i<n;i++)
			if(arr1[i]!=arr2[i])
				return 0;
		return 1;
	}
	return 0;

}
