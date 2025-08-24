/*7) write a function that can take an integer as input and return 1 if the number is prime number,  return 0 if it is not prime and print appropriate output message in main according to output.
	return type is integer. function name IsPrime - returns int (0 or 1)	*/
#include<stdio.h>
int Isprime(int n)
{
	int count=0;
	for(int i=2;i<=n/2;i++)
	{
		if(n%i==0){
			count++;
			break;
		}
	}
	if(count==0 && n>1)
		return 1;
	else
		return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(Isprime(n)==1)
		printf("It is a Prime\n");
	else
		printf("Not a prime\n");
	return 0;
}
