/*Write a program to read two numbers, and print all prime numbers between the given numbers.
	print how many prime numbers are there at the end.	*/
#include<stdio.h>
int main()
{
	int n1,n2,count=0;
	scanf("%d%d",&n1,&n2);
	printf("Primes:\n");
	for(;n1<=n2;n1++)
	{
		
		int temp=0;
		int j=2;
		while(j<n1)
		{
			if(n1%j==0)
				temp=1;
			j++;
		}
		if(temp==0 && n1>1){
			printf("%d\n",n1);
			count++;
		}
	}
	printf("count=%d\n",count);
	return 0;
}
