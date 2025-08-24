//Write a program to read 3 numbers and print the biggest of them:

#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("Enter 4 numbers:");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>b)
	{
		if(a>c)
		{
			if(a>d)
				printf("%d is big\n",a);
			else
				printf("%d is big\n",d);
		}
		else
		{
			if(c>d)
				printf("%d is big\n",c);
			else
				printf("%d is big\n",d);
				
		}		
	}
	else if(b>c)
	{
			if(b>d)
				printf("%d is big\n",b);
			else
				printf("%d is big\n",d);
	}
	else if(c>d)
	{
			printf("%d is big\n",c);
	}
	else
		printf("%d is big\n",d);
	return 0;
}
