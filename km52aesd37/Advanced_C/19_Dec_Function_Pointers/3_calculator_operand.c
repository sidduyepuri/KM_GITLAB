/*
3)"Write the calculator program using a function that accepts a function pointer and the operand values as arguments and invokes it. In the main function, simply invoke this function by sending the appropriate function address, based on the operator chosen.
eg.,
in main
case '+' :invokeptr(add , x,y);


invokeptr(int (*fptr) (int,int) , int x, int y)
{
printf(""%d\n"",fptr(x,y));
}"
*/
#include<stdio.h>
int main()
{
	int add(int ,int);
	int sub(int ,int);
	int mul(int ,int);
	int div(int ,int);
	int mod(int ,int);
	void invokeptr(int (*fptr) (int,int) , int, int);
	int a,b;
	char ch;
	scanf("%d %c%d",&a,&ch,&b);
	switch(ch)
	{
		case '+': invokeptr(add,a,b);
			  break;
		case '-': invokeptr(sub,a,b);
			  break;
		case '*': invokeptr(mul,a,b);
			  break;
		case '/': invokeptr(div,a,b);
			  break;
		case '%': invokeptr(mod,a,b);
			  break;
		default: printf("Enter valid operand\n");
	}
}
void invokeptr(int (*fptr) (int,int) , int x, int y)
{
	printf("%d\n",fptr(x,y));
}
int add(int x,int y)
{
	return x+y;
}
int sub(int x,int y)
{
	return x-y;
}
int mul(int x,int y)
{
	return x*y;
}
int div(int x,int y)
{
	return x/y;
}
int mod(int x,int y)
{
	return x%y;
}

