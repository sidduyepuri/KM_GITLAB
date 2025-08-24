/*1) Write a program with a function that takes two integer arguments, and prints all prime numbers between those numbers using the prime number function written above.return type should be void.
	PrintAllPrimes - return type is void. Should use IsPrime() function written yesterday.	*/
#include"main1.h"
int main()
{
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	PrintPrimes(n1,n2);
	return 0;
}
