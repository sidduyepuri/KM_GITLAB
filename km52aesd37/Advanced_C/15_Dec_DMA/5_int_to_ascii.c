//5) Implement itoa function and return the string from the function. Print the result in main. itoa function takes an integer as input, and stores the integer in a string.

#include<stdio.h>
#include<stdlib.h>
char * int_to_ascii(int);
int main()
{
	int n;
	scanf("%d",&n);
	char *str=(char *)malloc(n*sizeof(char));
	str=int_to_ascii(n);
	printf("%s\n",str);
}
char * int_to_ascii(int n)
{
	int a=n,c=0,i,j;
	char temp;
	while(a>0)
	{
		a=a/10;
		c++;
	}
	char *str=(char *)malloc(c*sizeof(char));
	for(i=c-1;n>0;i--)
	{
		str[i]=(n%10)+48;
		n/=10;
	}
	return str;	
}

