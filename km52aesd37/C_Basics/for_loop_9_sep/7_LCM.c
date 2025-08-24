//Find the LCM of 2 given numbers
#include<stdio.h>
int main()
{
	int a,b,lcm=1;
	scanf("%d%d",&a,&b);
	int j=a<b?a:b;
	for(int i=2;i<=j;i++)
	{	
		if(a%i==0&&b%i==0){
			a/=i;
			b/=i;
			lcm*=i;
			i=2;
		}
	}
	lcm*=(a*b);
	printf("%d\n",lcm);
	return 0;
}
