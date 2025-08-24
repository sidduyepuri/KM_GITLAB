/*1   Implement the calculator program using Command line arguments

eg., input:  >./calc   56 + 671
output : 727

note: when giving * in commandline, always give "*"		*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int a,b;
	char ch;
	a=atoi(argv[1]);
	b=atoi(argv[3]);
	ch=argv[2][0];
	switch(ch)
	{
		case '+': printf("%d\n",a+b);
			  break;
		case '-': printf("%d\n",a-b);
			  break;
		case '*': printf("%d\n",a*b);
			  break;
		case '/': printf("%d\n",a/b);
			  break;
		case '%': printf("%d\n",a%b);
			  break;
	}
	
}
