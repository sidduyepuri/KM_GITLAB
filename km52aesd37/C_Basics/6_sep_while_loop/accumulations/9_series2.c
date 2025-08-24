/*Find the value of the below series upto n terms:
	1 - 1/2 + 1/3 - 1/4 .... 1/n	*/
#include<stdio.h>
int main()
{
	int i=1,n;
	float sum=0;
	scanf("%d",&n);
	while(i<=n)
	{
		float j=i;
		if(i%2==0)
			sum-=1/j;
		else
			sum+=1/j;
		i++;
	}
	printf("%f\n",sum);
	return 0;

}
