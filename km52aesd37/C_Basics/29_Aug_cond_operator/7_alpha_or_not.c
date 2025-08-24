//check if a character is alphabet or not
#include<stdio.h>
int main()
{
	char ch;
	scanf("%c",&ch);
	ch<='z'?ch>='a'?printf("it is a alphabet\n"):ch<='Z'?ch>='A'?printf("It is a alphabet\n"):printf("Not an alphabet\n"):printf("Not an alphabet\n"):printf("Not an alphabet\n");
	return 0;
		
}
