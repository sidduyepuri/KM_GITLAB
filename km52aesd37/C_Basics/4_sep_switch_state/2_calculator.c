// Write the calculator program using switch case statement.

#include<stdio.h>
int main()
{
	int a,b;
	char ch;
	scanf("%d %c%d",&a,&ch,&b);
	switch(ch)
	{
		case '+': printf("a+b=%d\n",a+b);
			  break;		
		case '-': printf("a-b=%d\n",a-b);
			  break;
		case '*': printf("a*b=%d\n",a*b);
			  break;
		case '/': printf("a/b=%d\n",a/b);
			  break;
		case '%': printf("a%%b=%d\n",a%b);
			  break;
		default: printf("You entered wrong operator\n");
	}
	return 0;
}
