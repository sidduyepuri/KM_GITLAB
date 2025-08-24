//2)  Write down a macro to find the biggest of four numbers using biggest of 2 macro.
#include<stdio.h>
#define MAX(w,x) w>x?w:x
#define Max(y,z) y>z?y:z
#define MAXI(w,x,y,z) (MAX(w,x))>(Max(y,z))?(MAX(w,x)):(Max(y,z))
int main()
{
	int a,b,c,d;
	printf("Enter 4 values:");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("Big is=%d\n",MAXI(a,b,c,d));
	return 0;
}
