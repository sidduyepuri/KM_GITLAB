/*Rewrite the calculator program so that the main function is in main.c , remaining functions are in another source code file, operations.c.
  1) Create the operand variables as global variables and use them in the operation functions directly, without passing as arguments. Function returns the result as return value.	*/
#include<stdio.h>
int fun();
int a,b;
char ch;
int main()
{
	scanf("%d %c%d",&a,&ch,&b);
	printf("%d\n",fun());
	/*switch(ch)
	{
		case '+': printf("add=%d\n",fun()); break;
		case '-': printf("sub=%d\n",fun()); break;
		case '*': printf("mul=%d\n",fun()); break;
		case '/': printf("quotient=%d\n",fun()); break;
		case '%': printf("remainder=%d\n",fun()); break;
		default: printf("Invalid operator\n");
	} */
	return 0;
}
