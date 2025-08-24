//6) Write two source files, main.c and swap.c. The main function initializes a two-element array of ints, and then calls the swap function to swap the pair.
#include<stdio.h>

int main()
{
	int n,i;
	printf("Enter size of array:");
	scanf("%d",&n);
	int arr1[n],arr2[n];

	for(i=0;i<n;i++)
		scanf("%d",arr1[i]);
	for(i=0;i<n;i++)
		scanf("%d",arr2[i]);
	for(i=0;i<n;i++){
	swap();
	for(i=0;i<n;i++)
		printf("%d",arr1[i]);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d",arr2[i]);
	printf("\n");
	return 0;
}
