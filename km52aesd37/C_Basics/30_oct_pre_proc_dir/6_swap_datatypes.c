//6)  define a macro to generate swapping function for int, float , double and character datatypes, as a generic function using macros.
#include<stdio.h>
#define SWAPPING(w,x,y,z) temp=w,w=x,x=y,y=z,z=temp
int main()
{
	int a,temp;
	float b;
	double c;
	char d;
	scanf("%d%f%lf %c",&a,&b,&c,&d);
	SWAPPING(a,b,c,d);
	printf("a=%d\nb=%f\nc=%lf\nd=%d\n",a,b,c,d);
	return 0;
}
