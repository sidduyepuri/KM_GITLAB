#include<stdio.h>
int count_bits(int);
int main()
{
	int n;
	printf("Enter number:");
	scanf("%d",&n);
	int i=count_bits(n);
	printf("no of one's=%d\n",i);
	return 0;
}
int count_bits(int n)
{
	int count=0;
	while(n>0){
		n=n&(n-1);
		count++;
	}
	return count;
}
