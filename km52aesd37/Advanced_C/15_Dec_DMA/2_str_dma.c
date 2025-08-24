//2) create a string dynamically, read and print its value.

#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *str=(char *)malloc(20*sizeof(char));
	scanf("%s",str);
	printf("%s\n",str);
}
