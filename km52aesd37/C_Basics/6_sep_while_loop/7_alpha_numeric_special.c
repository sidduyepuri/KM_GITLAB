// read n characters from user, and print if every character is alphabet / numeric / special character.
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
			case 'a' ... 'z' : printf("It is a alphabet\n");
						break;
			case 'A' ... 'Z' : printf("It is a alphabet\n");
						break;
			case '0' ... '9' : printf("It is a numeric\n");
						break;
			default : printf("It is a special character\n");
		}
	i++;
	}
	return 0;
}
