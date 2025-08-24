#include<stdio.h>
int main()
{
	float l,b;
	float area,peri;
	scanf("%f%f",&l,&b);
	area=l*b;
	peri=2*(l+b);
	printf("area=%f\nperimeter=%f\n",area,peri);
	return 0;
}

