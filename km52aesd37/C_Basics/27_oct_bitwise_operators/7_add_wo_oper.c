//7. WAP implements addition functionality without using ADD('+') Operator.   

#include<stdio.h>
int main()
{
	int x,y,add;
	printf("Enter x and y:");
	scanf("%d%d",&x,&y);
	y=~y+1;
	add=x-y;
	printf("Addition=%d\n",add);
	return 0;
}
