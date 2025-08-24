/*
5) Read an integer and print it back using function pointers for printf and scanf.

printf declaration to use : int printf(char * , ...);
scanf declaration to use : int scanf(char *, ...);

Try it again using alias name and array of function pointers.
*/
#include<stdio.h>
int main()
{
	int (*fp[])(const char *,...)={scanf,printf};
	int n,i=0;
	char name[10];
	while(i<2)
	{
		if(i==0)
			fp[i]("%d",&n);
		else
			fp[i]("%d\n",n);
		i++;
	}
	i=0;
	while(i<2)
	{
		fp[i]("%s",name);
		i++;
	}
	fp[1]("\n");
}
