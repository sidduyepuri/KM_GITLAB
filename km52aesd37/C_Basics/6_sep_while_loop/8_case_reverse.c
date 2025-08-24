// read n characters from user and if the character is alphabet, then print its case reverse. if it is not a character, print it as it is.
#include<stdio.h>
int main()
{
	int i=1,n;
	scanf("%d",&n);
	while(i<=n)
	{
		char ch;
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'a' ... 'z' : printf("%c\n",ch-32);
						break;
			case 'A' ... 'Z' : printf("%c\n",ch+32);
						break;
			default : printf("%c\n",ch);
		}
	i++;
	}
	return 0;
}
