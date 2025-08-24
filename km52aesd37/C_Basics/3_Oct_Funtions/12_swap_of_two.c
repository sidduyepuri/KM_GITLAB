//12) Write a function ,that can take two integers, swap their values and print their new values. return type should be void. function should print the values.
#include<stdio.h>
void swap(int a,int b)
{
	a=a+b;
	b=a-b;
	a=a-b;
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	return;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	swap(a,b);
	return 0;
}
