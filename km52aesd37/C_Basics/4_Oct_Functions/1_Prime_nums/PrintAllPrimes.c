#include"main1.h"
int Isprime(int,int);
void PrintPrimes(int n1,int n2)
{
	for(int i=n1;i<=n2;i++)
	{
		int count=0;
		if(Isprime(i,count)==1)
			printf("%d\n",i);

	}
}
int Isprime(int i,int c)
{
		for(int j=2;j<=i/2;j++)
		{
			if(i%j==0){
				c++;
				break;
			}
		}
		if(c==0&&i>1)
			return 1;
		return 0;
}
