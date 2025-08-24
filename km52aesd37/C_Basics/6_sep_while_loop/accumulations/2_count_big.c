//Read a set of n numbers only in ascending order. While reading the numbers, if the user enters a bigger number than previous number, then count it and continue to the next number. If the number is smaller than previous number, then do not count it, and continue to read the next number.
#include<stdio.h>
int main()
{
	int i=1,n,big=0;
	scanf("%d",&n);
	while(i<=n)
	{
		int m;
		scanf("%d",&m);
		if(m>big){
			big=m;
			printf("%d ",big);
		}
		i++;
	}
	printf("\n");
	return 0;
}
