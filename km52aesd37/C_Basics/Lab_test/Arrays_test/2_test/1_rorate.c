#include<stdio.h>
int rotate(int arr[],int d,int n);
int main()
{
	int d,n,i;
	printf("Enter no of elements:");
	scanf("%d",&n);
	printf("Enter rotate times:");
	scanf("%d",&d);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	rotate(arr,d,n);
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}
int rotate(int arr[],int d,int n)
{
	int i,j,temp;
	for(i=0;i<d;i++){
		for(j=0;j<n;j++){
			if(j==0){
				temp=arr[j];
				arr[j]=arr[j+1];
			}
			else if(j<n-1)
				arr[j]=arr[j+1];
			else if(j==n-1)
				arr[j]=temp;
		}
		temp=0;
	}
}
