/*Find the value of the below series upto n terms:
	9 + 99 + 999 + 9999 + .........upto n terms	*/
#include<stdio.h>
int main()
{
	int i=1,n,sum=0,temp=0;
	scanf("%d",&n);
	while(i<=n)
	{
		temp=temp*10+9;
		sum+=temp;
		i++;
	}
	printf("%d\n",sum);
	return 0;

}
