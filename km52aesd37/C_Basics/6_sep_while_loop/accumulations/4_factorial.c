/*Write a program to find the factorial of a given number.
	N! = n * n-1 * n-2 * …. 2 * 1     */
#include<stdio.h>
int main()
{
	int i=2,n,fact=1;
	scanf("%d",&n);
	while(i<=n)
	{
		fact*=i;
		i++;
	}
	printf("factorial=%d\n",fact);
	return 0;
}
