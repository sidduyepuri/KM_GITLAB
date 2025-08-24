extern int a,b;
extern char ch;
int fun()
{
	switch(ch)
	{
		case '+': return a+b;
		case '-': return (a-b);
		case '*': return a*b;
		case '/': return a/b;
		case '%': return a%b;	
	}
}
