/*Write a program to read two numbers, and print all prime numbers between the given numbers. print how many prime numbers are there at the end.		*/
#include<stdio.h>
int main()
{
	int n1,n2,count=0;
	scanf("%d%d",&n1,&n2);
	printf("Primes:\n");
	for(int i=n1;i<=n2;i++)
	{
		int temp=0;
		int j=2;
		while(j<i)
		{
			if(i%j==0){
				temp++;
				break;
			}
			j++;
		}
		if(temp==0 && i>1){
			printf("%d\n",i);
			count++;
		}
	}
	printf("count=%d\n",count);
	return 0;
}
