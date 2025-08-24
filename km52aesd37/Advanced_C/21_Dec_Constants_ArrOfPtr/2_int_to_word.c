/*2) read an integer number, display the number as a number name expansion.
	eg., 458 : four five eight		*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	int n,r=0,res,i=0,count=0;
	char str2[10];
	scanf("%d",&n);
	while(n>0)
	{
		str2[i]=(n%10)+48;
		n/=10;
		i++;
	}
	str2[i]='\0';
	int l=strlen(str2);
	while(l>0)
	{
		n=l-1;
		res=str2[n]-48;
		printf("%s ",str[res]);
		l--;
	}
	printf("\n");
}
