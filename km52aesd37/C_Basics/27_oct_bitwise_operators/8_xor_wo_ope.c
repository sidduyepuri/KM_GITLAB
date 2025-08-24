//8. WAP implements XOR functionality without using XOR(^) operator.

#include<stdio.h>
int main()
{
	int x,y,z;
	scanf("%d%d",&x,&y);
	z=(~x)&y|(~y)&x;
	printf("xor=%d\n",z);
	return 0;
}
