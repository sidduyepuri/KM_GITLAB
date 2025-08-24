/*
4)
"Write the calculator program using a function that accepts an array of function pointers and the operand values and operator character as arguments and invokes appropriate function based on the character. In main function, simply invoke this function by sending the array and operator character and operands as input.
eg.,
in main
case '+' :invokeptr( fparr, x,y, ch);


invokeptr(int (*fptr[]) (int,int) , int x, int y ,char ch)
{
//based on ch value, choose which index to apply on fptr and invoke the function
}
*/
#include<stdio.h>
int add(int ,int);
int sub(int ,int);
int mul(int ,int);
int div(int ,int);
int mod(int ,int);
void invokeptr(int (*fparr[]) (int,int) , int x, int y,char ch);
int main()
{
	int a,b;
	char ch;
	int (*fparr[])(int,int)={add,sub,mul,div,mod};
	scanf("%d %c%d",&a,&ch,&b);
	invokeptr(fparr,a,b,ch);
}
void invokeptr(int (*fparr[]) (int,int) , int x, int y,char ch)
{
	int i=0;
	while(i<5)
	{
		if(i==0&&ch=='+')
			printf("%d\n",fparr[i](x,y));
		if(i==1&&ch=='-')
			printf("%d\n",fparr[i](x,y));
		if(i==2&&ch=='*')
			printf("%d\n",fparr[i](x,y));
		if(i==3&&ch=='/')
			printf("%d\n",fparr[i](x,y));
		if(i==4&&ch=='%')
			printf("%d\n",fparr[i](x,y));
		i++;
	}
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

