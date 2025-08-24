//Read a character and print if the given character is an alphabet or not.

#include<stdio.h>
int main()
{
	char ch;
	printf("Enter alphabet:");
	scanf("%c",&ch);
	if (ch<='z')
	{
		if(ch>='a')
			printf("%c is alphabet\n",ch);
		else if(ch<='Z')
		{
			if(ch>='A')
				printf("%c is alphabet\n",ch);
			else
				printf("%c is not an alphabet\n",ch);
		}
		else
				printf("%c is not an alphabet\n",ch);
	}
	else	
				printf("%c is not an alphabet\n",ch);
	return 0;
}
