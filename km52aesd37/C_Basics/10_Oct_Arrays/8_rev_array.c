/*8 Write a program to reverse an array and print it (Reverse the array by swapping both edges of the array and move inside and repeat till middle of the array):  
Input : array1 ={1,2,3,4,5};
Output : array1 = {5,4,3,2,1};		*/
#include<stdio.h>
void reverse(int arr[],int);
int main()
{
	int n,i;
	printf("Enter size of the array:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	reverse(arr,n);
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}

void reverse(int arr[],int n)
{
	int i,j,temp;
	for(i=0,j=n-1;i<j;i++,j--){
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}
