//Read a character and print if the given character is a digit or not.

#include<stdio.h>
int main()
{
	char ch;
	printf("Enter digit:");
	scanf("%c",&ch);
	if (ch<='9')
	{
		if(ch>='0')
			printf("%c is a digit\n",ch);
		else
			printf("%c is not a digit\n",ch);
	}
	else	
				printf("%c is not a digit\n",ch);
	return 0;
}
