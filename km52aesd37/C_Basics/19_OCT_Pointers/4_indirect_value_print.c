//4 Declare 3 integer variables. Declare an integer pointer. Assign the address of each variable to the pointer in succession and print the value of the variable using indirection operator on the pointer.
#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int *p=&a;
	printf("a=%d\n",*p);
	p=&b;
	printf("b=%d\n",*p);
	p=&c;
	printf("c=%d\n",*p);
	return 0;
}
