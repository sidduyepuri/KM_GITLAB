//Take three input integers x,y and z. Write a program to rotate their values such that, x has the value of y, y has the value of z and z has the value of x.
#include<stdio.h>
int main()
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	y=x+y+z;
	x=y-x-z;
	z=y-x-z;
	y=y-x-z;
	printf("x=%d\ny=%d\nz=%d\n",x,y,z);
	return 0;
}
