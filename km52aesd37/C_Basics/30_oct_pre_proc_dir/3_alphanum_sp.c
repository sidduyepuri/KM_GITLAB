//3)  WAP to print if  a character is alphanumeric or special character, using macro conditions
#include<stdio.h>
#define ALPHANUM(c) c<='z'&&c>='a'||c<='Z'&&c>='A'||c<='9'&&c>='0'
int main()
{
	char ch;
	printf("Enter a character:");
	scanf(" %c",&ch);
	if(ALPHANUM(ch))
		printf("Alphanumeric\n");
	else
		printf("Special character\n");
	return 0;
}
