// Read 4 numbers and print which of them is biggest.
#include<stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>b && a>c && a>d)
		printf("big=%d\n",a);
	else if(b>c && b>d)
		printf("big=%d\n",b);
	else if(c>d)
		printf("big=%d\n",c);
	else
		printf("big=%d\n",d);
	return 0;

}
