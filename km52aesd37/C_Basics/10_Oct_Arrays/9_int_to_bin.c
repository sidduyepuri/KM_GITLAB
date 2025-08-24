//9 Write a program to print an integer in binary format using arrays.
#include<stdio.h>
int main()
{
	int n,i,c=0;
	scanf("%d",&n);
	int arr[15];
	for(i=0;n>0;i++){
		arr[i]=n%2;
		n/=2;
	}
	c=i;
	for(i=c-1;i>=0;i--)
		printf("%d",arr[i]);
	printf("\n");
	return 0;
}	
