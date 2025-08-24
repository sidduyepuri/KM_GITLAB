//1 Write a program to print the address of a variable , its value ,its size, try different executions and note the address printed. Assign the address of the variable to a pointer variable.Print the size of pointer and its indirected value (apply * operator).
#include<stdio.h>
int main()
{
	int x;
	int *ptr=&x;
	scanf("%d",ptr);
	printf("X address:&x:%p\n",&x);
	printf("X value:&x:%d\n",x);
	printf("X size:&x:%lu\n",sizeof(x));
	printf("ptr(&x) address:ptr:%p\n",ptr);
	printf("*ptr(x) value:*ptr:%d\n",*ptr);
	printf("size of ptr:ptr:%lu\n",sizeof(ptr));
	return 0;	
}
