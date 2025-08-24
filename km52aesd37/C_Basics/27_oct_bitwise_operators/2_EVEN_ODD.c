//2. WAP whether a number is ODD or EVEN using bitwise.

#include<stdio.h>
int main()
{
	int n;
	printf("Enter value:");
	scanf("%d",&n);
	if(n&0x1)
		printf("ODD\n");
	else
		printf("EVEN\n");
	return 0;
}
