#include<stdio.h>
int main()
{
	unsigned int a=0xaabbccdd;
	int b=a>>20;
	int c=(a<<12)>>12;
	printf("original a:%x\n",a);
	printf("value 1:%x\n",b);
	printf("value 2:%x\n",c);
	return 0;
}
