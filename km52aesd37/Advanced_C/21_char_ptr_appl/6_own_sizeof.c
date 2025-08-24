//6) Define a sizeof macro that will find the size of a given variable as a parameter, using pointers.

#include<stdio.h>
#include<stdlib.h>
#define mysizeof(x) (char *)(&x+1)-(char *)&x
int main()
{
	int a;
	char ch;
	float b;
	double d;
	printf("sizeof int:%ld\n",mysizeof(a));
	printf("sizeof char:%ld\n",mysizeof(ch));
	printf("sizeof float:%ld\n",mysizeof(b));
	printf("sizeof double:%ld\n",mysizeof(d));
	return 0;
}
