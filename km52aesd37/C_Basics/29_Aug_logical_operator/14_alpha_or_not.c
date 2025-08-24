//Read a character and print if it is alphabet or not.
#include<stdio.h>
int main()
{
	char ch;
	scanf("%c",&ch);
	if(ch<='z'&&ch>='a'||ch<='Z'&&ch>='A')
		printf("alphabet\n");
	else
		printf("not an alphabet\n");
}
