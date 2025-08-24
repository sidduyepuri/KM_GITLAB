#include<stdio.h>
int main()
{
	int n;
	printf("Enter no of elements:");
	scanf("%d",&n);
	int arr[n],arr2[n],i,j,prod=1;
	printf("Enter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			if(arr[i]!=arr[j])
				prod*=arr[j];
			arr2[i]=prod;
			prod=1;
	}
	for(i=0;i<n;i++)
		printf("%d ",arr2[i]);
	printf("\n");
}
