//8 Take three input integers x,y and z. Write a program to rotate their values such that, x has the value of y, y has the value of z and z has the value of x. Do this using pointers that point to x,y and z.
#include<stdio.h>
int main()
{
	int x,y,z;
	int *a=&x,*b=&y,*c=&z;
	scanf("%d%d%d",a,b,c);
	*c=*a+*b+*c;
	*b=*c-*a-*b;
	*a=*c-*a-*b;
	*c=*c-*a-*b;
	printf("x=%d\ny=%d\nz=%d\n",x,y,z);
	return 0;
}
