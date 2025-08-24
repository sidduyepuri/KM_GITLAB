//swap the values of 2 variables.

#include<stdio.h>
int main()
{
	int a,b,c;
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	c=b;
	b=a;
	a=c;
	printf("a=%d\nb=%d\n",a,b);
	return 0;
}
