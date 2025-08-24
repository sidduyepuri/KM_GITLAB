//without using * and / operator print power of a number
#include<stdio.h>
int main()
{
	int a,b,pow=0,temp=0;
	scanf("%d%d",&a,&b);
	pow=a;
	for(int i=1;i<b;i++)
	{
		temp=0;
		for(int j=1;j<=a;j++)
		{
			temp+=pow;
		}
		pow=temp;
	}
	printf("power=%d\n",pow);
}

