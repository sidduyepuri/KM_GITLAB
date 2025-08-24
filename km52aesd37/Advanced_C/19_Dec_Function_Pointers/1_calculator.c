//1)Write the calculator program using function pointers for add, sub, mul, div and mod functions, using a single function pointer.
#include<stdio.h>
int main()
{
	int add(int,int);
	int sub(int,int);
	int mul(int,int);
	int div(int,int);
	int mod(int,int);
	int a,b;
	scanf("%d%d",&a,&b);
	int (*p)(int ,int)=add;
	int c=p(a,b);
	printf("Addition=%d\n",c);
	p=sub,c=p(a,b);
	printf("Subtraction=%d\n",c);
	p=mul,c=p(a,b);
	printf("mul=%d\n",c);
	p=div,c=p(a,b);
	printf("quotient=%d\n",c);
	p=mod,c=p(a,b);
	printf("remainder=%d\n",c);
	return 0;
}
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
	return a/b;
}
int mod(int a,int b)
{
	return a%b;
}
