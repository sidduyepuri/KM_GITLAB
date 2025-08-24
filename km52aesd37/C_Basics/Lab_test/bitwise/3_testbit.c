#include<stdio.h>
int testbits(int,int);
int main()
{
	int num,p;
	printf("Enter num and p:");
	scanf("%d%d",&num,&p);
	if(testbits(num,p))
		printf("True\n");
	else
		printf("False\n");
	return 0;
}
int testbits(int n,int p)
{
	if(p>15||p<0)
		return 0;
	else{
		if(n&0x1<<p)
			return 1;
		else
			return 0;
	}
}
