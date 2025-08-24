//6. WAP implements subtraction functionality without using SUB('-') Operator.    

#include<stdio.h>
int main()
{
	int x,y,sub;
	printf("Enter x and y:");
	scanf("%d%d",&x,&y);
	y=~y+1;
	sub=x+y;
	printf("subtraction=%d\n",sub);
	return 0;
}
