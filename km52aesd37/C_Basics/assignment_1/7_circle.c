#include<stdio.h>
#include<math.h>
int main()
{
	int r;
	float area,peri;
	scanf("%d",&r);
	area=3.14*r*r;
	peri=2*3.14*r;
	printf("area=%f\nperimeter=%f\n",area,peri);
	return 0;
}
