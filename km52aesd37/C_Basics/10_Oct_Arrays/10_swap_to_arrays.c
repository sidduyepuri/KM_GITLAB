/*10 Write a program to swap two arrays in reverse order.
eg.,
input : array1 = {1,2,3,4,5};
array2 = {6,7,8,9,10};
output:
array1 : {10,9,8,7,6}
array2: { 5,4,3,2,1}		*/

#include<stdio.h>
void reverse(int arr1[],int,int arr2[]);
int main()
{
	int n,i,temp;
	printf("Enter size of the array:");
	scanf("%d",&n);
	int arr1[n],arr2[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr1[i]);
	for(i=0;i<n;i++)
		scanf("%d",&arr2[i]);
	reverse(arr1,n,arr2);
	for(i=0;i<n;i++)
		printf("%d\t",arr1[i]);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d\t",arr2[i]);
	printf("\n");

	return 0;
}

void reverse(int arr1[],int n,int arr2[])
{
	int i,j,temp;
	for(i=0,j=n-1;i<n;i++,j--){
		temp=arr1[i];
		arr1[i]=arr2[j];
		arr2[j]=temp;
	}
}
