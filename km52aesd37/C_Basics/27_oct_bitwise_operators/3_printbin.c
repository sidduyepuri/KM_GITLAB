/*3. Write a printbinary(int , int ) function consists of 2 integer variables. First one is value of the variable and second one is  size of variable. 
		Example: 
			char x=5; 
			printbinary(x,sizeof(x)); 
			output:  00000101			*/
#include<stdio.h>
void printbinary(int,int);
int main()
{
	char a=14;
	short int b=10;
	int c=20;
	printbinary(a,sizeof(a));
	printbinary(b,sizeof(b));
	printbinary(c,sizeof(c));
	return 0;
}
void printbinary(int x,int size)
{
	int i;
	for(i=0;i<(size*8);i++)
	{
		if(x&(0x1<<(size*8)-1))
			printf("1");
		else
			printf("0");
		x=x<<1;
	}
	printf("\n");
}

