//Find the HCF of 2 given numbers
#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int i=a<b?a:b;
	for(;i>1;i--)
	{
		if((a%i==0)&&(b%i==0)){
			printf("HCF=%d\n",i);
			break;
		}
	}
	return 0;
}
