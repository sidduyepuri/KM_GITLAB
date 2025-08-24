#include<stdio.h>
int main()
{
	int p,n;
	float r,si,m;
	printf("Please enter principle,time in months and rate of interest: ");
	scanf("%d%d%f",&p,&n,&r);
	m=n/12.0;
	si=p*m*r/100;
	printf("simple interest=%f\n",si);
	return 0;

}
