//9 Declare an integer array of size 10 and initialize it to some values. Print the addresses of each element of the array using a pointer. using indirection operator , print the value stored in each element of the array.
#include<stdio.h>
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int *ptr=&arr[0];
	for(int i=0;i<10;i++){
		ptr=&arr[i];
		printf("%d-%p\n",*ptr,ptr);
	}	
	return 0;
}

