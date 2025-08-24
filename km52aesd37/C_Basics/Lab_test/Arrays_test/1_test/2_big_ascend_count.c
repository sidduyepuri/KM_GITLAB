#include<stdio.h>
int main()
{
	int n,i,big,temp=0,count=1,j;
	printf("Enter size of an array:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[j]>arr[i])
				count++;
			else{
				break;
			}
			i++;
		}
		if(count>temp)
			temp=count;
		count=1;
	}
	printf("count=%d\n",temp);
}
