//7) Try to send a character array / character pointer / string constant as arguments and see what is the size returned, and understand the difference.
	
#include<stdio.h>
#include<stdlib.h>
#define mysizeof(x) (char *)(&x+1)-(char *)&x
int main()
{
	char *ch;
	char str[10];
	char *str1="Kernel";
	printf("sizeof char:%ld\n",mysizeof(ch));
	printf("sizeof float:%ld\n",mysizeof(str));
	printf("sizeof double:%ld\n",mysizeof(str1));
	return 0;
}
