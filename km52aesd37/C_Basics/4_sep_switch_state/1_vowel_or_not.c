//C program to check whether a character is vowel or not using switch statement

#include<stdio.h>
int main()
{
	char ch;
	scanf("%c",&ch);
	switch(ch)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U': printf("it is vowel\n");
			  break;
		default: printf("Not an vowel\n");
	
	}
	return 0;
}
