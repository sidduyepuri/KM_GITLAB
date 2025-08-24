/*9) Write a calculator program with 5 functions below to do the operations of addition, subtraction, multiplication, division for quotient and division for remainder.
1) int add (int a, int b) // to be called when user chooses +
2) int sub (int a,int b) // to be called when user chooses -
3) int mul(int a, int b) // to be called when user chooses *
4) int quotient(int a, int b) // to be called when user chooses /
5) int remainder(int a,int b) // to be called when user choose%		*/
#include<stdio.h>
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int Quo(int a,int b)
{
	return a/b;
}
int Rem(int a,int b)
{
	return a%b;
}
int main()
{
	int a,b;
	char ch;
	scanf("%d %c%d",&a,&ch,&b);
	switch(ch)
	{
	case '+': printf("Addition=%d\n",add(a,b));
		  break;
	case '-': printf("Subtraction=%d\n",sub(a,b));
		  break;
	case '*': printf("Multiplication=%d\n",mul(a,b));
		  break;
	case '/': printf("Quotient=%d\n",Quo(a,b));
		  break;	
	case '%': printf("Remainder=%d\n",Rem(a,b));
		  break;
	default: printf("wrong operator\n");
	}
	return 0;
}
