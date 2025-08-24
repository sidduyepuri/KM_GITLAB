//3 Declare an array of size 10. Enter 10 elements and save them in the array. Print the array . Find out the biggest and smallest numbers and their indexes and print.
#include<stdio.h>
int main()
{
	int n;
	printf("Enter size of the array:");
	scanf("%d",&n);
	int arr[n];
	int i,j,k,big,small;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	big=small=arr[0];
	j=k=0;
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
		if(arr[i]>big){
			big=arr[i];
			j=i;
		}
		if(arr[i]<small){
			small=arr[i];
			k=i;
		}
	}
	printf("\nBiggest number is arr[%d]=%d\n",j,big);	
	printf("Smallest number is arr[%d]=%d\n",k,small);

}

