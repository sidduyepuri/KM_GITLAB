//1) Write a function to calculate simple interest. Call it in main function with appropriate inputs and print the total amount the user will get after the tenure (principle + interest)
#include<stdio.h>
int simple_interest(int p,int t,float r)
{
	int si;
	si=(p*t*r)/100;
	return si+p;
}
int main()
{
	int p,t;
	float r,si;
	scanf("%d%d%f",&p,&t,&r);
	si=simple_interest(p,t,r);
	printf("Simple Interest=%f\n",si);
	return 0;
}
