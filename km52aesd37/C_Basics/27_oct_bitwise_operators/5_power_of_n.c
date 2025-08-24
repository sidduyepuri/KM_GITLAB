//5. WAP whether a number is a power of 2 or not?
#include<stdio.h>
int main()
{
	int n,i;
	printf("Enter value:");
	scanf("%d",&n);
	if(!(n&(n-1)))
		printf("It is a power of 2\n");
	else
		printf("not a power of 2\n");
	return 0;
}
