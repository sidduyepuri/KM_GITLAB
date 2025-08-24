#include<stdio.h>
int main()
{
	int amount;
	printf("Enter amount to withdraw:");
	scanf("%d",&amount);
	printf("Money dispensed as Follows:\n");
	printf("No of 2000/- notes:%d\n",amount/2000);
	amount%=2000;
	printf("No of 500/- notes:%d\n",amount/500);
	amount%=500;
	printf("No of 200/- notes:%d\n",amount/200);
	amount%=200;
	printf("No of 100/- notes:%d\n",amount/100);
	amount%=100;
	printf("No of 50/- notes:%d\n",amount/50);
	return 0;
	
}
