//C program to find biggest of two numbers using switch statement

#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=a>b;
	switch(c)
	{
		case 1: printf("%d is big\n",a);
			break;
		case 0: printf("%d is big\n",b);
			break;
	}

}
