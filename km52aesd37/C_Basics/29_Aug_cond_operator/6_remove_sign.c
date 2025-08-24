//Take an integer as input and print its magnitude (remove sign).

#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	n>0?printf("%d\n",n):printf("%d\n",-n);
	return 0;
}

