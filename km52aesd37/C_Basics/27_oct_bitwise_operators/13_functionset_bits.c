/*13. Write a functionsetbits(x,p,n,y)that return x with then bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
	e.g. if x = 10101010 (170 decimal) and y = 10100111 (167 decimal) and n = 3 and p = 6 then
	you need to strip off 3 bits of y (111) and put them in x at position 10xxx010 to get answer
	10111010. Your answer should print out the result in binary form although input can be in
	decimal form.
	Your output should be like this:
		x = 10101010 (binary)
		y = 10100111 (binary)
	setbits n = 3, p = 6 gives x = 10111010 (binary).*/
#include<stdio.h>
int function_set_bits(int,int,int,int);
void printbinary(int x,int size);
int main()
{
	int x,y,p,n,i;
	printf("Enter x and y:");
	scanf("%d%d",&x,&y);
	printf("Enter n value:");
	scanf(" %d",&n);
	printf("Enter position:");
	scanf(" %d",&p);
	i=function_set_bits(x,p,n,y);
	printbinary(x,8);
	printbinary(y,8);
	printbinary(i,8);
	return 0;
}
int function_set_bits(int x,int p,int n,int y)
{
	y=y&(0x1<<n)-1;
	y=y<<(p-n);
	x=x&~y|y;
	return x;
}
void printbinary(int x,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(x&0x80)
			printf("1");
		else
			printf("0");
		x=x<<1;
	}
	printf("\n");
}
