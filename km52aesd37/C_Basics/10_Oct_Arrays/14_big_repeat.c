/*14) write a function to take an array as input, and count how many times the biggest number is repeated in that array, and return the count.
	eg., array : {10, 14,16,10, 10 , 16, 14, 14, 16, 16};
	output : biggest number is repeated 4 times	*/

#include<stdio.h>
int repeat(int arr[],int);
int main()
{
	int n;
	printf("Enter size of the array:");
	scanf("%d",&n);
	int arr[n];
	int i,count;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	count=repeat(arr,n);
	printf("\nBiggest number repeated %d times\n",count);	

}
int repeat(int arr[],int n)
{
	int i,big,count=0;
	big=arr[0];
	for(i=0;i<n;i++)
		if(arr[i]>big)
			big=arr[i];
	for(i=0;i<n;i++)
		if(big==arr[i])
			count++;
	return count;
}
