#include<stdio.h>
int main()
{
	int n,i,j;
	printf("Enter no of elements:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++){
		if(arr[i]==0)
		for(j=i+1;j<n;j++){
			if(arr[j]!=0){
				arr[i]=arr[j];
				arr[j]=0;
				break;
		}
	}
	}
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;

}
