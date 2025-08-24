//write a program to print values of all data types using input and output functions
#include<stdio.h>
int main()
{
	int a;
	char b;
	float c;
	double d;
	unsigned int e;
	short int f;
	unsigned short int g;
	long int h;
	unsigned long int i;
	long double j;
	unsigned char k;
	scanf("%d %c%f%lf%u%hd%hu%ld%lu%Lf %c",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k);
	printf("a:%d\nb:%c\nc:%f\nd:%lf\ne:%u\nf:%hd\ng:%hu\nh:%ld\ni:%lu\nj:%Lf\nk:%c\n",a,b,c,d,e,f,g,h,i,j,k);
	return 0;
}
