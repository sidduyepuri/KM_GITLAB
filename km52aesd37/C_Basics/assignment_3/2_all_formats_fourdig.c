/*read a 4 digit number and print it in the following formats:
		eg., 4532*/
#include<stdio.h>
int main()
{
	int n,temp;
	scanf("%d",&n);
	temp=n;
	printf("%d\n",temp%10);
	temp/=10;
	printf("%d\n",temp%10);	
	temp/=10;
	printf("%d\n",temp%10);
	temp/=10;
	printf("%d\n",temp%10);	
	printf("..............\n");
	temp=n;//
	printf("%d\n",temp/1000);
	temp%=1000;
	printf("%d\n",temp/100);	
	temp%=100;
	printf("%d\n",temp/10);
	temp%=10;
	printf("%d\n",temp/1);	
	printf("..............\n");
	temp=n;
	printf("%d\n",temp/1000);
	printf("%d\n",temp/100);	
	printf("%d\n",temp/10);
	printf("%d\n",temp/1);	
	printf("..............\n");
	temp=n;
	printf("%d\n",temp/1);
	printf("%d\n",temp/10);	
	printf("%d\n",temp/100);
	printf("%d\n",temp/1000);	
	printf("..............\n");
	temp=n;
	printf("%d",temp%10);
	temp/=10;
	printf("%d",temp%10);	
	temp/=10;
	printf("%d",temp%10);
	temp/=10;
	printf("%d\n",temp%10);	
	printf("..............\n");
	temp=n;
	printf("%4d\n",temp%10);
	temp/=10;
	printf("%3d\n",temp%10);	
	temp/=10;
	printf("%2d\n",temp%10);
	temp/=10;
	printf("%d\n",temp%10);	
	printf("..............\n");
	
	return 0;


}
