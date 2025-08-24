#include<stdio.h>
int main()
{
	int i,j,n,k,count=0,temp,m;
	printf("Enter no of elements:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
				if(arr[i]==arr[j])
				{
					arr[i]=arr[j];
					for(k=j;k<n;k++){
			
						if(k<n-1)
							arr[j]=arr[j+1];
						n--;
						k--;
					}
				}
			}
	}
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}
