/*1) Write down a macro to find out the biggest of two numbers.
     MAX(x,y) should define code to find biggest of x and y. Implement array sorting function using this macro (Bubble sort)	*/
#include<stdio.h>
void array_sorting();
#define MAX(x,y) x>y?x:y
int main()
{
	int a,b;
	printf("Enter a and b:");
	scanf("%d%d",&a,&b);
	printf("Big is=%d\n",MAX(a,b));
	array_sorting();
	return 0;
}
void array_sorting()
{
	int n,i,j,temp;
	printf("Enter array size:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(MAX(arr[j],arr[j+1])==arr[j]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}
