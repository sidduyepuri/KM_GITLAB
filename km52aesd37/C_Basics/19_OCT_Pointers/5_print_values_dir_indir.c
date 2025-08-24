//5 Declare 3 pointer variables of integer type, and an integer variable. Assign the address of integer variable to the 3 pointers. Print the variable value using indirection on each pointer variable. Change the variable value directly and check the values of each of the pointers using indirection. Change the variable value , using each pointer and print the variable value and indirected values of all pointers every time you change.
#include<stdio.h>
int main()
{
	int a;
	int *x=&a,*y=&a,*z=&a;
	printf("Enter 'a' value:");
	scanf("%d",&a);
	printf("Value of a=%d\n",a);
	printf("Value of x=%d\n",*x);
	printf("Value of y=%d\n",*y);
	printf("Value of z=%d\n",*z);
	printf("Enter 'x' value:");
	scanf("%d",x);
	printf("Value of a=%d\n",a);
	printf("Value of x=%d\n",*x);
	printf("Value of y=%d\n",*y);
	printf("Value of z=%d\n",*z);
	printf("Enter 'y' value:");
	scanf("%d",y);
	printf("Value of a=%d\n",a);
	printf("Value of x=%d\n",*x);
	printf("Value of y=%d\n",*y);
	printf("Value of z=%d\n",*z);
	printf("Enter 'z' value:");
	scanf("%d",z);
	printf("Value of a=%d\n",a);
	printf("Value of x=%d\n",*x);
	printf("Value of y=%d\n",*y);
	printf("Value of z=%d\n",*z);
	
}
