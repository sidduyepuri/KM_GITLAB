#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j;
	char str[50];
	scanf("%[^\n]s",str);
	int len=strlen(str);
	len=(len/2)+1;
	for(i=1;i<=len;i++)
	{
		for(j=1;j<=len-i;j++)
			printf(" ");
		n=i;
		for(j=1;j<=i;j++){
			printf("%c",str[n-1]);
			n++;
		}
		n=n-2;
		for(j=1;j<=i-1;j++){
			printf("%c",str[n-1]);
			n--;
		}
		printf("\n");
		
	}
}
