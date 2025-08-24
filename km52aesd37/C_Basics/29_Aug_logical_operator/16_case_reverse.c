//Input an alphabet. Output its case reverse.
#include<stdio.h>
int main()
{
	char ch;
	scanf("%c",&ch);
	if(ch<='z'&&ch>='a')
		printf("UPPER=%c\n",ch-32);
	else if(ch<='Z'&&ch>='A')
		printf("LOWER=%c\n",ch+32);
	else
		printf("Not an alphabet\n");
}
