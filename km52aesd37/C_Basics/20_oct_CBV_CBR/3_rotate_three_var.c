//3) Write a function that can rotate the values of three variables. print the results in the main function.
#include<stdio.h>
void rotate(int *,int *,int *);
int main()
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	rotate(&x,&y,&z);
	printf("x=%d\ny=%d\nz=%d\n",x,y,z);
	return 0;
}
void rotate(int *a,int *b,int *c)
{
	int t;
	t=*a;
	*a=*b;
	*b=*c;
	*c=t;
}
