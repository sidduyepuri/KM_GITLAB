/*Find the value of the below series upto n terms:
	1 + 1/2 + 1/3 + 1/4 .... 1/n	*/
#include<stdio.h>
int main()
{
	int n,i=1;
	float sum=0;
	scanf("%d",&n);
	while(i<=n)
	{
		float j=i;
		sum+=1/j;
		i++;
	}
	printf("%f\n",sum);
	return 0;

}
