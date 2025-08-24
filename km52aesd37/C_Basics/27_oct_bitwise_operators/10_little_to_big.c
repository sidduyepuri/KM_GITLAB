//10. WAP to convert Little endian integer to Big endian integer

#include<stdio.h>
int main()
{
	unsigned int x;
	scanf("%x",&x);
	x=x<<24|x>>24|x<<8&0x00ff0000|x>>8&0x0000ff00;
	printf("%x\n",x);
	return 0;
}
