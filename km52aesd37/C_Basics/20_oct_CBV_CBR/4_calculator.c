//4) Write a function that can take two integers as input, and gives 5 outputs : addition, subtraction, multiplication, quotient and reminder of those two numbers. Print the outputs in the main function.
#include<stdio.h>
int *a,*b,*c,*d,*e;
void calculator(int,int);
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	calculator(x,y);
	printf("addition=%d\n",*a);
	printf("subtraction=%d\n",*b);
	printf("multiplication=%d\n",*c);
	printf("quotient=%d\n",*d);
	printf("remainder=%d\n",*e);
}
void calculator(int p,int q)
{
	int s=p+q;
	a=&s;
	int t=p-q;
	b=&t;
	int u=p*q;
	c=&u;
	int v=p/q;
	d=&v;
	int w=p%q;
	e=&w;
}
