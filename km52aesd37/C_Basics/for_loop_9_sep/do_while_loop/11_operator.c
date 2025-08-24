/*Modify the Calculator Program to take input and perform the chosen operation. If the user chooses one of the operations, +,-,*,/ and % then show the output and continue for next iteration.
If the user chooses wrong operation, then stop the loop.*/
#include<stdio.h>
int main()
{
	int a,b;
	char ch;
	do
	{
		scanf("%d %c%d",&a,&ch,&b);
		if(ch=='+')
			printf("Addition=%d\n",a+b);
		else if(ch=='-')
			printf("Subtraction=%d\n",a-b);
		else if(ch=='*')
			printf("Multiplication=%d\n",a*b);
		else if(ch=='/')
			printf("Quotient=%d\n",a/b);
		else if(ch=='%')
			printf("Remainder=%d\n",a%b);
		else
			break;
	}while(1);
	return 0;
}
