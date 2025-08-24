//Input an alphabet. Output its case reverse.

#include<stdio.h>
int main()
{
	char ch;
	scanf("%c",&ch);
	ch<='z'?ch>='a'?printf("%c\n",ch-32):ch<='Z'?ch>='A'?printf("%c\n",ch+32):printf("Not an alphabet\n"):printf("Not an alphabet\n"):printf("Not an alphabet\n");
	return 0;
		
}
