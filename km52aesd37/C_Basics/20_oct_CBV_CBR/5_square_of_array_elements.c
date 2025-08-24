/*5) "Write a function that communicates with main using a single static variable without taking any input arguments.
Everytime function returns something using the static variable,after using it, main sends another input using the same variable and calls the function again.
eg., print the square of each number of an array :
for each number of the array :
    call the function
    main gets the static variable address as return value from function.
    main puts the array element in static variable.
in the function :
    create static variable.
    if static variable value is not zero, print its square.
    function sends static variable address back to main."		*/
#include<stdio.h>
int * fun();
int main()
{
	int n,i,*p;
	printf("Enter array size:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter array elements:");
	for(i=0;i<n;i++){
	
	scanf("%d",&arr[i]);
}
	p=fun();
	for(i=0;i<n;i++){
		*p=arr[i];	
		fun();
		printf("%d ",*p);
		}
	
}
int * fun()
{
	static int x;
	if(x!=0)
		x=x*x;
	if(x==0)
		return &x;
}
