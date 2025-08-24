/*	print the below patterns wihtout using nested for loop:
	1
	0 1
	1 0 1
	0 1 0 1
	1 0 1 0 1				*/
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int j=1;
		while(j<=i)
		{
			printf("%d ",((i+j)%2==0));
			j++;
		}	
		printf("\n");
	}
}
