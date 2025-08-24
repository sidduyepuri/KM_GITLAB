//4)  Define  a macro that receives an array and the number of elements in the array as arguments. Write a program using this macro to print out the elements of the array. Try using this macro for different data types of arrays.
#include<stdio.h>
#define ARR(arr,SIZE) arr[SIZE] 
int main()
{
	int n;
	scanf("%d",&n);
	int ARR(arr1,n);
	char ARR(arr2,n);
	float ARR(arr3,n);
	double ARR(arr4,n);
	int i;
	printf("Enter integer array:");
	for(i=0;i<n;i++)
		scanf("%d",&ARR(arr1,i));
	printf("Enter character array:");
	for(i=0;i<n;i++)
		scanf(" %c",&ARR(arr2,i));
	printf("Enter float array:");
	for(i=0;i<n;i++)
		scanf("%f",&ARR(arr3,i));
	printf("Enter double array:");
	for(i=0;i<n;i++)
		scanf("%lf",&ARR(arr4,i));
	for(i=0;i<n;i++)
		printf("%d ",ARR(arr1,i));
	printf("\n");
	for(i=0;i<n;i++)
		printf("%c ",ARR(arr2,i));
	printf("\n");
	for(i=0;i<n;i++)
		printf("%f ",ARR(arr3,i));
	printf("\n");
	for(i=0;i<n;i++)
		printf("%lf ",ARR(arr4,i));	
	printf("\n");
}
