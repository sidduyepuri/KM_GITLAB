//2) Create the operand variables as global variables and use them in the operation functions directly, without passing as arguments. Function return value should be stored in another global variable in the operations file and be used to print in main.
#include<stdio.h>
void fun();
int a,b;
char ch;
extern int c;
int main()
{
	scanf("%d %c%d",&a,&ch,&b);
	fun();
	printf("%d\n",c);
	return 0;
}
