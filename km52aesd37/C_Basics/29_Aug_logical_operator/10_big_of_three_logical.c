//Read 3 numbers and print which of them is the biggest.
#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b && a>c)
		printf("big=%d\n",a);
	else if(b>c)
		printf("big=%d\n",b);
	else
		printf("big=%d\n",c);
	return 0;

}
