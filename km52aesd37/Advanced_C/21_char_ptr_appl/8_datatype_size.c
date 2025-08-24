//8) Define a sizeof macro that will find the size of a given data type as a parameter. use pointers.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size(x) sizeof(x)
int main()
{
	printf("sizeof char:%ld\n",size(char));
	printf("sizeof int:%ld\n",size(int));
	printf("sizeof float:%ld\n",size(float));
	printf("sizeof double:%ld\n",size(double));
	printf("sizeof long double:%ld\n",size(long double));
	printf("sizeof short int:%ld\n",size(short int));
	return 0;
}
