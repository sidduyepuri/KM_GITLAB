//2)Rewrite the calculator program using an array of function pointers.
#include<stdio.h>
int main()
{
	void add(int,int);
	void sub(int,int);
	void mul(int,int);
	void div(int,int);
	void mod(int,int);
	int a,b,i=0;
	scanf("%d%d",&a,&b);
	void (*p[])(int ,int)={add,sub,mul,div,mod};
	while(i<5)
	{
		p[i](a,b);
		i++;
	}
	return 0;
}
void add(int a,int b)
{
	printf("add=%d\n",a+b);
}
void sub(int a,int b)
{
	printf("sub=%d\n",a-b);
}
void mul(int a,int b)
{
	printf("mul=%d\n",a*b);
}
void div(int a,int b)
{
	printf("quotient=%d\n",a/b);
}
void mod(int a,int b)
{
	printf("rem=%d\n",a%b);
}
