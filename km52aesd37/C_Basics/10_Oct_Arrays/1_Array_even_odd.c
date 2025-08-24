/*1 Write the following program :
Declare an integer array of size 100.
Assign numbers 1-100 to each element of the array.
Print all the numbers.
Print all even elements.
Print all odd elements.
Add 5 to each element and print 6 – 105 numbers.	*/
#include<stdio.h>
int main()
{
	int arr[100];
	int i,j;
	for(i=0,j=1;i<100,j<=100;i++,j++)
		arr[i]=j;
	for(i=0;i<100;i++)
		printf("%d\t",arr[i]);
	printf("\nEven numbers:\n");
	for(i=0;i<100;i++)
		if(arr[i]%2==0)
			printf("%d\t",arr[i]);	
	printf("\nOdd numbers:\n");
	for(i=0;i<100;i++)
		if(arr[i]%2!=0)
			printf("%d\t",arr[i]);
	printf("\nplus 5 numbers\n");
	for(i=0;i<100;i++)
		printf("%d\t",arr[i]+5);
	printf("\n");

		
	
}
