//5) Define a generic function, for different types of array printing , by taking array and array size as arguments
#include<stdio.h>
#define SIZE 10
#define ARR(arr,SIZE) arr[SIZE] 
int main()
{
	int ARR(arr,SIZE);
	int i;
	printf("Enter integer array:");
	for(i=0;i<SIZE;i++)
		scanf("%d",&ARR(arr,i));
	for(i=0;i<SIZE;i++)
		printf("%d ",ARR(arr,i));	
	printf("\n");
}
